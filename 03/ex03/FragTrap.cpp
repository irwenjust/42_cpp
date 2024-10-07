/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:31:35 by likong            #+#    #+#             */
/*   Updated: 2024/10/03 09:30:27 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name){
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called\n";
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other){
	std::cout << "FragTrap " << other._name << " as a copy constructor called\n";
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << this->_name << " distructor called\n";
}

FragTrap	&FragTrap::operator = (const FragTrap &other){
	std::cout << "FragTrap copy assignment operator called\n";
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

void	FragTrap::attack(const std::string &target){
	if (this->_hitPoints == 0)
		std::cout << "FragTrap " << this->_name << " is dead. Can't attack anymore\n";
	else if (this->_energyPoints == 0)
		std::cout << "FragTrap " << this->_name << " doesn't have any more energy to attack\n";
	else {
		this->_energyPoints--;
		std::cout << "FragTrap " << this->_name << " attack " << target
		<< " with " << this->_attackDamage << " damage\n";
	} 
}

void	FragTrap::highFivesGuys(){
	std::cout << "FragTrap " << this->_name << " displays a positive high fives request\n";
}
