#pragma once

#include <concepts>
#include <cstddef>
#include <iostream>

template <typename T, typename Func>
requires std::invocable<Func, T&>
void iter(T* array, std::size_t length, Func function) {
    if (!array) {
        std::cout << "Error: Empty array\n";
        return;
    }
    for (std::size_t i = 0; i < length; ++i)
        function(array[i]);
}
