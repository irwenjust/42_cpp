/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:21:44 by likong            #+#    #+#             */
/*   Updated: 2025/10/15 10:21:44 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <concepts>
#include <cstddef>

template <typename T, typename Func>
requires std::invocable<Func, T&>
void iter(T* array, std::size_t length, Func function) {
    if (!array)
        return;
    for (std::size_t i = 0; i < length; ++i)
        function(array[i]);
}

template <typename T, typename Func>
requires std::invocable<Func, const T&>
void iter(const T* array, std::size_t length, Func function) {
    if (!array)
        return;
    for (std::size_t i = 0; i < length; ++i)
        function(array[i]);
}
