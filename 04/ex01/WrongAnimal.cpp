/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:18:46 by likong            #+#    #+#             */
/*   Updated: 2024/10/04 12:37:18 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("other"){
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): _type(other._type){
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal distructor called\n";
}

WrongAnimal	&WrongAnimal::operator = (const WrongAnimal &other){
	std::cout << "WrongAnimal copy assignment operator called\n";
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

std::string	WrongAnimal::getType() const{
	return (this->_type);
}

void	WrongAnimal::makeSound() const{
	std::cout << "Other Wronganimal will call like @#@#%@#$@%$\n";
}
