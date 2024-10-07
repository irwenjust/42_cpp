/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 08:30:00 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 13:41:30 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("empty"), _hitPoints(10), _energyPoints(10),
_attackDamage(0){
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hitPoints(10),
_energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap " << name << " constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name),
_hitPoints(other._hitPoints),
_energyPoints(other._energyPoints),
_attackDamage(other._attackDamage){
	std::cout << "ClapTrap " << other._name << " as a copy constructor called\n";
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->_name << " distructor called\n";
}

ClapTrap	&ClapTrap::operator = (const ClapTrap &other){
	std::cout << "Claptrap copy assignment operator called\n";
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target){
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead. Can't attack anymore\n";
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " doesn't have any more energy to attack\n";
	else {
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attack " << target << "\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints == 0){
		std::cout << "ClapTrap " << this->_name << " is dead. Can't take any more damage\n";
		return ;
	}
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " take " << amount << " damage\n";
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead\n";
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead. Can't take any more damage\n";
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " doesn't have any more energy to attack\n";
	else {
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " has been repaired. get "
				<< amount << " hit point back. Now the total hit point is "
				<< this->_hitPoints << std::endl;
	}
}


