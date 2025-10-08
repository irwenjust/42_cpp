/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:15:32 by likong            #+#    #+#             */
/*   Updated: 2025/10/06 11:15:33 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint> //uintptr_t
#include "Data.hpp"

class Serializer {
	private:
		Serializer(void) = delete;
		Serializer(const Serializer &other) = delete;
		~Serializer(void) = delete;
		Serializer &operator=(const Serializer &other) = delete;

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};