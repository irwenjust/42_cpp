/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:15:21 by likong            #+#    #+#             */
/*   Updated: 2025/10/06 11:15:22 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <iomanip> //std::setprecission
#include <exception>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOFLOAT,
	PSEUDODOUBLE,
	UNKNOWN
};

class ScalarConverter {
	private:
		ScalarConverter(void) = delete;
		ScalarConverter(const ScalarConverter &other) = delete;
		~ScalarConverter(void) = delete;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;

	public:
		static void convert(const std::string &str);
};
