// main.cpp
#include <cassert>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Array.hpp"

// --- tiny test harness ---
static int g_pass = 0, g_fail = 0;
#define CHECK(msg, cond) do { \
    if (cond) { ++g_pass; } else { ++g_fail; std::cerr << "[FAIL] " << msg << "\n"; } \
} while(0)

struct CopyCounter {
    int value = 0;
    static int copies;
    CopyCounter() = default;
    explicit CopyCounter(int v) : value(v) {}
    CopyCounter(const CopyCounter& rhs) : value(rhs.value) { ++copies; }
    CopyCounter& operator=(const CopyCounter& rhs) { value = rhs.value; ++copies; return *this; }
};
int CopyCounter::copies = 0;

struct ThrowOnCopy {
    int value = 0;
    ThrowOnCopy() = default;
    explicit ThrowOnCopy(int v) : value(v) {}
    ThrowOnCopy(const ThrowOnCopy&) { throw std::runtime_error("copy boom"); }
    ThrowOnCopy& operator=(const ThrowOnCopy&) { throw std::runtime_error("assign boom"); }
};

int main() {
    std::cout << "== Array<T> test suite ==\n";

    // 1) default-constructed is empty; operator[] should throw
    {
        Array<int> a;
        CHECK("default size==0", a.size() == 0);
        bool threw = false;
        try { (void)a[0]; } catch (const std::out_of_range&) { threw = true; }
        CHECK("default operator[] throws", threw);
    }

    // 2) sized constructor + write/read + bounds checks
    {
        Array<int> a(5);
        CHECK("sized size==5", a.size() == 5);
        for (std::size_t i = 0; i < a.size(); ++i) a[i] = int(i * 10);
        bool ok = true;
        for (std::size_t i = 0; i < a.size(); ++i) ok &= (a[i] == int(i * 10));
        CHECK("read/write works", ok);

        bool threwLow = false, threwHigh = false;
        try { (void)a[5]; } catch (const std::out_of_range&) { threwHigh = true; }
        try { (void)a[9999]; } catch (const std::out_of_range&) { threwLow = true; }
        CHECK("bounds check high", threwHigh);
        CHECK("bounds check very high", threwLow);
    }

    // 3) const correctness (const operator[])
    {
        Array<int> a(3);
        for (std::size_t i = 0; i < a.size(); ++i) a[i] = int(i + 1);
        const Array<int>& ca = a;
        int sum = 0;
        for (std::size_t i = 0; i < ca.size(); ++i) sum += ca[i];
        CHECK("const access ok", sum == 6);
        bool threw = false;
        try { (void)ca[3]; } catch (const std::out_of_range&) { threw = true; }
        CHECK("const out_of_range", threw);
    }

    // 4) copy constructor makes deep copy
    {
        Array<std::string> a(3);
        a[0] = "alpha"; a[1] = "beta"; a[2] = "gamma";
        Array<std::string> b = a; // copy-construct
        CHECK("copy same size", b.size() == a.size());
        CHECK("copy content eq", b[0] == "alpha" && b[1] == "beta" && b[2] == "gamma");

        // mutate original; copy should not change
        a[1] = "BETA!";
        CHECK("copy deep independence", b[1] == "beta");
    }

    // 5) copy assignment + self-assignment safety
    {
        Array<int> a(4);
        for (std::size_t i = 0; i < a.size(); ++i) a[i] = int(i);
        Array<int> b(1);
        b = a; // copy-assign
        bool same = (b.size() == a.size());
        for (std::size_t i = 0; i < a.size(); ++i) same &= (b[i] == a[i]);
        CHECK("copy assignment content", same);

        // self-assignment shouldn't break things
        std::size_t oldSize = b.size();
        b = b;
        CHECK("self-assign keeps size", b.size() == oldSize);
        bool intact = true; for (std::size_t i = 0; i < b.size(); ++i) intact &= (b[i] == int(i));
        CHECK("self-assign keeps content", intact);
    }

    // 6) copy count sanity with a custom type (ensures element-wise copy happens)
    {
        CopyCounter::copies = 0;
        Array<CopyCounter> a(3);
        for (std::size_t i = 0; i < a.size(); ++i) a[i] = CopyCounter(int(i));
        Array<CopyCounter> b = a; // copy ctor
        CHECK("copy counter nonzero", CopyCounter::copies >= 3); // at least copies during copy-ctor
    }

    // 7) exception-safety smoke test (copy throws). The Array should remain usable after a failed op.
    {
        Array<ThrowOnCopy> a(1);
        bool threw = false;
        try {
            Array<ThrowOnCopy> b = a; // copy-construct should throw
            (void)b;
        } catch (const std::runtime_error&) {
            threw = true;
        }
        CHECK("throwing copy propagates", threw);

        // Also try assignment; object should remain in a valid state (no UB/crash)
        Array<ThrowOnCopy> x(1), y(1);
        bool threw2 = false;
        try { x = y; } catch (const std::runtime_error&) { threw2 = true; }
        CHECK("throwing assign propagates", threw2);
    }

    // 8) zero-sized arrays behave (operator[] still throws)
    {
        Array<std::string> a(0);
        CHECK("zero size ok", a.size() == 0);
        bool threw = false;
        try { (void)a[0]; } catch (const std::out_of_range&) { threw = true; }
        CHECK("zero size index throws", threw);
    }

    // (Optional) Compile-time negative test: non-default-constructible T will fail for sized-ctor.
    // struct NoDefault { NoDefault(int){} };
    // Array<NoDefault> nd(3); // should NOT compile by design (your constructor value-initializes elements)

    std::cout << "== Summary: " << g_pass << " passed, " << g_fail << " failed ==\n";
    return g_fail ? 1 : 0;
}
