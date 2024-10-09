/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:16:45 by likong            #+#    #+#             */
/*   Updated: 2024/10/08 16:02:45 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal(){
	std::cout << "Dog default constructor called\n";
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other): Animal(other){
	std::cout << "Dog copy constructor called\n";
	this->_brain = new Brain(*other._brain);
}

Dog::~Dog(){
	std::cout << "Dog distructor called\n";
	delete this->_brain;
	this->_brain = nullptr;
}

Dog	&Dog::operator = (const Dog &other){
	std::cout << "Dog copy assignment operator called\n";
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

void	Dog::makeSound() const{
	std::cout << "Wang\n";
}
