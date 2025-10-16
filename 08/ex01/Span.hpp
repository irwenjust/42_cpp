/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:17:01 by likong            #+#    #+#             */
/*   Updated: 2025/10/16 12:17:02 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <concepts>
#include <iterator>
#include <ranges>

class Span {
private:
    unsigned int _size;
    std::vector<int> _numbers;

public:
    Span() = default;
    Span(unsigned int n);
    Span(const Span&) = default;
    Span& operator=(const Span&) = default;
    ~Span() = default;

    void addNumber(int n);

    // Template must stay in header
    template <std::input_iterator It>
    requires std::convertible_to<std::iter_value_t<It>, int>
    void addNumbers(It first, It last) {
        for (; first != last; ++first) {
            if (_numbers.size() >= _size)
                throw std::overflow_error("Too many numbers for this Span");
            _numbers.push_back(static_cast<int>(*first));
        }
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};
