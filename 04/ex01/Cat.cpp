/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:16:30 by likong            #+#    #+#             */
/*   Updated: 2024/10/08 16:03:33 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal(){
	std::cout << "Cat default constructor called\n";
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other): Animal(other){
	std::cout << "Cat copy constructor called\n";
	this->_brain = new Brain(*other._brain);
}

Cat::~Cat(){
	std::cout << "Cat distructor called\n";
	delete this->_brain;
	this->_brain = nullptr;
}

Cat	&Cat::operator = (const Cat &other){
	std::cout << "Cat copy assignment operator called\n";
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	if (this->_brain != nullptr){
		delete this->_brain;
		this->_brain = nullptr;
	}
	this->_brain = new Brain(*other._brain);
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << "miao\n";
}
