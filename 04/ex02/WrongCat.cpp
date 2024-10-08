/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:19:07 by likong            #+#    #+#             */
/*   Updated: 2024/10/04 12:37:49 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
	std::cout << "WrongCat default constructor called\n";
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other){
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat distructor called\n";
}

WrongCat	&WrongCat::operator = (const WrongCat &other){
	std::cout << "WrongCat copy assignment operator called\n";
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

void	WrongCat::makeSound() const{
	std::cout << "awo\n";
}
