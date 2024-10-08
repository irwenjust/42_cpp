/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:16:04 by likong            #+#    #+#             */
/*   Updated: 2024/10/07 19:44:55 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("other"){
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &other): _type(other._type){
	std::cout << "Animal copy constructor called\n";
}

Animal::~Animal(){
	std::cout << "Animal distructor called\n";
}

Animal	&Animal::operator = (const Animal &other){
	std::cout << "Animal copy assignment operator called\n";
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

std::string	Animal::getType() const{
	return (this->_type);
}
