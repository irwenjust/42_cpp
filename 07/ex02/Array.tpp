#include "Array.hpp"

template <typename T>
Array<T>::Array(): _array(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(const std::size_t n): _size(n) {
    _array = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> &other): _size(other._size) {
    _array = (_size > 0) ? new T[_size] : nullptr;

    for (std::size_t i = 0; i < _size; i++)
        _array[i] = other._array[i];
}

template <typename T>
Array<T>::~Array() {delete[] _array;}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
    if (this != &other) {
        delete[] _array;
        _size = other._size;
        _array = (_size > 0) ? new T[_size] : nullptr;
        for (std::size_t i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](std::size_t index) {
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return (_array[index]);
}

template <typename T>
const T& Array<T>::operator[](std::size_t index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return (_array[index]);
}

template <typename T>
std::size_t Array<T>::size() const {return _size;}
