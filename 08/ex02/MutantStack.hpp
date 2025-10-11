#pragma once

#include <stack>
#include <deque>
#include <concepts>
#include <ranges>
#include <iterator>

template <
    class T,
    class Container = std::deque<T>
>
requires (
    // Stack’s container must store T …
    std::same_as<typename Container::value_type, T> &&
    // …and be at least bidirectional (so rbegin/rend work).
    std::ranges::bidirectional_range<Container>
)
class MutantStack : public std::stack<T, Container> {
public:
    // Use the base class constructors (same behavior as std::stack)
    using std::stack<T, Container>::stack;

    // Rule of 5 — defaulted (C++20 style: concise & correct)
    MutantStack() = default;
    MutantStack(const MutantStack&) = default;
    MutantStack(MutantStack&&) noexcept = default;
    MutantStack& operator=(const MutantStack&) = default;
    MutantStack& operator=(MutantStack&&) noexcept = default;
    ~MutantStack() = default;

    // Iterator aliases (ranges-friendly)
    using iterator               = std::ranges::iterator_t<Container>;
    using const_iterator         = std::ranges::iterator_t<const Container>;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // Iteration over the *underlying* container (protected member `c`)
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end();   }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end()   const { return this->c.end();   }

    const_iterator cbegin() const { return this->c.cbegin(); }
    const_iterator cend()   const { return this->c.cend();   }

    reverse_iterator rbegin() { return reverse_iterator{end()}; }
    reverse_iterator rend()   { return reverse_iterator{begin()}; }

    const_reverse_iterator rbegin() const { return const_reverse_iterator{end()}; }
    const_reverse_iterator rend()   const { return const_reverse_iterator{begin()}; }

    const_reverse_iterator crbegin() const { return const_reverse_iterator{cend()}; }
    const_reverse_iterator crend()   const { return const_reverse_iterator{cbegin()}; }
};
