/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:23:42 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 16:49:32 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called\n";
	this->_value = value << this->_fract_bits;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called\n";
	this->_value = roundf(value * (1 << this->_fract_bits));
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	if (this != &other){
		std::cout << "Copy assignment operator called\n";
		this->_value = other.getRawBits();
	}
	return (*this);
}

std::ostream &operator << (std::ostream &os, const Fixed &other){
	os << other.toFloat();
	return (os);
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void)  const{
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void	Fixed::setRawBits(int const raw){
	std::cout << "getRawBits member function called\n";
	this->_value = raw;
}

float	Fixed::toFloat(void) const{
	return (static_cast<float>(this->_value) / (1 << this->_fract_bits));
}

int	Fixed::toInt(void) const{
	return (this->_value >> this->_fract_bits);
}
