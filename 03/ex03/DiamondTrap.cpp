/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:49:21 by likong            #+#    #+#             */
/*   Updated: 2024/10/03 09:25:39 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap(), _name("Diamond"){
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = 50;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"),
_name(name){
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = 50;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << name << " constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other),
_name(other._name){
	this->_energyPoints = 50;
	std::cout << "DiamondTrap " << other._name << " as a copy constructor called\n";
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << this->_name << " distructor called\n";
}

DiamondTrap	&DiamondTrap::operator = (const DiamondTrap &other){
	std::cout << "DiamondTrap copy assignment operator called\n";
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	ScavTrap::operator=(other);
	FragTrap::operator=(other);
	return (*this);
}

void	DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(){
	std::cout << "This name is " << this->_name
			<< " and the Claptrap name is " << ClapTrap::_name << std::endl;
	std::cout << this->_name << "'s hit: " << this->_hitPoints
			<< ". The energy is " << this->_energyPoints
			<< ". The attack is " << this->_attackDamage << std::endl;
}
