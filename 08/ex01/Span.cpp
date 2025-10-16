/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:16:58 by likong            #+#    #+#             */
/*   Updated: 2025/10/16 12:16:59 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _size(n), _numbers() {
    _numbers.reserve(n);
}

void Span::addNumber(int n) {
    if (_numbers.size() >= _size)
        throw std::overflow_error("Span is full");
    _numbers.push_back(n);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to compute a span");

    std::vector<int> sorted = _numbers;
    std::ranges::sort(sorted);

    unsigned int best = std::numeric_limits<unsigned int>::max();

    for (std::size_t i = 1; i < sorted.size(); ++i) {
        unsigned int diff = static_cast<unsigned int>(
            static_cast<long long>(sorted[i]) - static_cast<long long>(sorted[i - 1])
        );
        if (diff < best)
            best = diff;
        if (best == 0)
            return 0;
    }
    return best;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to compute a span");

    auto [minIt, maxIt] = std::ranges::minmax_element(_numbers);
    long long diff = static_cast<long long>(*maxIt) - static_cast<long long>(*minIt);
    return static_cast<unsigned int>(diff);
}
