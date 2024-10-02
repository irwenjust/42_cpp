/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:23:42 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 16:49:47 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0){}

Fixed::Fixed(const int value){
	this->_value = value << this->_fract_bits;
}

Fixed::Fixed(const float value){
	this->_value = roundf(value * (1 << this->_fract_bits));
}

Fixed::Fixed(const Fixed &other){
	*this = other;
}

Fixed &Fixed::operator = (const Fixed &other){
	if (this != &other){
		this->_value = other.getRawBits();
	}
	return (*this);
}

std::ostream &operator << (std::ostream &os, const Fixed &other){
	os << other.toFloat();
	return (os);
}

Fixed::~Fixed(){}

int	Fixed::getRawBits(void)  const{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw){
	this->_value = raw;
}

bool	Fixed::operator>(const Fixed &other) const{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed &other) const{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other) const{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed &other) const{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other) const{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other) const{
	return (this->_value != other._value);
}

Fixed	Fixed::operator+(const Fixed &other) const{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other) const{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other) const{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other) const{
	if (other._value == 0)
		throw	std::runtime_error("Cannot divide by 0");
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::operator++(){
	++this->_value;
	return (*this);
}

Fixed	Fixed::operator++(int){
	Fixed	res = *this;
	++this->_value;
	return (res);
}

Fixed	&Fixed::operator--(){
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator--(int){
	Fixed	res = *this;
	--this->_value;
	return (res);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b){
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	else
		return (b);
}

const  Fixed	&Fixed::min(const Fixed &a, const Fixed &b){
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b){
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);
}

const  Fixed	&Fixed::max(const Fixed &a, const Fixed &b){
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);
}

float	Fixed::toFloat(void) const{
	return (static_cast<float>(this->_value) / (1 << this->_fract_bits));
}

int	Fixed::toInt(void) const{
	return (this->_value >> this->_fract_bits);
}
