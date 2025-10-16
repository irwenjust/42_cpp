/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:21:13 by likong            #+#    #+#             */
/*   Updated: 2025/10/15 10:21:14 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <concepts>
#include <utility>

template <typename T>
void	swap(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<std::totally_ordered T>
constexpr const T& min(const T& a, const T& b) {
	return (a < b ? a : b);
}

template<std::totally_ordered T>
constexpr const T& max(const T& a, const T& b) {
	return (a > b ? a : b);
}