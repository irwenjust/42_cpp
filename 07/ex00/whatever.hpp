#pragma once

#include <concepts>
#include <utility>

template <typename T>
void swap(T& a, T& b) noexcept(noexcept(std::swap(a, b))) {
	using std::swap;
	swap(a, b);
}

template<typename T>
constexpr const T& min(const T& a, const T& b) {
  return (a < b ? a : b);
}

template<typename T>
constexpr const T& max(const T& a, const T& b) {
  return (a < b ? b : a);
}