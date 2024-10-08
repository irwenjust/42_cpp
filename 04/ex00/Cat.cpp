/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:16:30 by likong            #+#    #+#             */
/*   Updated: 2024/10/07 16:45:55 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal(){
	std::cout << "Cat default constructor called\n";
	this->_type = "Cat";
}

Cat::Cat(const Cat &other): Animal(other){
	std::cout << "Cat copy constructor called\n";
}

Cat::~Cat(){
	std::cout << "Cat distructor called\n";
}

Cat	&Cat::operator = (const Cat &other){
	std::cout << "Cat copy assignment operator called\n";
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << "miao\n";
}
