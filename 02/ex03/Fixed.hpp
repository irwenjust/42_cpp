/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:23:33 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 16:49:48 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>

class Fixed{
	private:
		int					_value;
		static const int	_fract_bits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		~Fixed();

		Fixed				&operator = (const Fixed &number);

		bool				operator>(const Fixed &number) const;
		bool				operator<(const Fixed &number) const;
		bool				operator>=(const Fixed &number) const;
		bool				operator<=(const Fixed &number) const;
		bool				operator==(const Fixed &number) const;
		bool				operator!=(const Fixed &number) const;

		Fixed				operator+(const Fixed &number) const;
		Fixed				operator-(const Fixed &number) const;
		Fixed				operator*(const Fixed &number) const;
		Fixed				operator/(const Fixed &number) const;

		Fixed				&operator++();
		Fixed				operator++(int);
		Fixed				&operator--();
		Fixed				operator--(int);

		static Fixed		&min(Fixed &a, Fixed &b);
		const static Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		const static Fixed	&max(const Fixed &a, const Fixed &b);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
};

std::ostream	&operator << (std::ostream &os, const Fixed &numbers);
