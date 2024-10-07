/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:21:18 by likong            #+#    #+#             */
/*   Updated: 2024/10/03 09:29:47 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name){
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other){
	std::cout << "ScavTrap " << other._name << " as a copy constructor called\n";
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << this->_name << " distructor called\n";
}

ScavTrap	&ScavTrap::operator = (const ScavTrap &other){
	std::cout << "Scavtrap copy assignment operator called\n";
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

void	ScavTrap::attack(const std::string &target){
	if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " is dead. Can't attack anymore\n";
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " doesn't have any more energy to attack\n";
	else {
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attack " << target
		<< " with " << this->_attackDamage << " damage\n";
	} 
}

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->_name << "  is now in Gate keeper mode\n";
}
