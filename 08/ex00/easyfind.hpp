#include <concepts>
#include <ranges>
#include <algorithm>
#include <stdexcept>
#include <type_traits>

template <class R>
requires std::ranges::input_range<R> &&
         std::same_as<std::remove_cv_t<std::ranges::range_value_t<R>>, int>
auto easyfind(R&& r, int value) {
    auto it = std::ranges::find(r, value);
    if (it == std::ranges::end(r))
        throw std::runtime_error("Element not found");
    return it; // type: std::ranges::iterator_t<R>
}
