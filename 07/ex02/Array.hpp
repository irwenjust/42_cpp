#pragma once

#include <iostream>
#include <cstddef>

template <typename T>
class Array
{
private:
    T *_array;
    std::size_t _size;

public:
    Array();
    Array(std::size_t n);

    Array(const Array& other);
    Array& operator=(const Array& other);

    ~Array();

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    std::size_t size() const;
};

#include "Array.tpp"
