/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:38:49 by likong            #+#    #+#             */
/*   Updated: 2025/10/15 14:38:58 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
