/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:42:34 by likong            #+#    #+#             */
/*   Updated: 2024/10/04 13:47:23 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called\n";
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
}

Brain::Brain(const Brain &other){
	std::cout << "Brain copy constructor called\n";
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain::~Brain(){
	std::cout << "Brain distructor called\n";
}

Brain	&Brain::operator = (const Brain &other){
	std::cout << "Cat copy assignment operator called\n";
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	return (*this);
}
