/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:16:45 by likong            #+#    #+#             */
/*   Updated: 2024/10/07 16:46:11 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal(){
	std::cout << "Dog default constructor called\n";
	this->_type = "Dog";
}

Dog::Dog(const Dog &other): Animal(other){
	std::cout << "Dog copy constructor called\n";
}

Dog::~Dog(){
	std::cout << "Dog distructor called\n";
}

Dog	&Dog::operator = (const Dog &other){
	std::cout << "Dog copy assignment operator called\n";
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << "Wang\n";
}
