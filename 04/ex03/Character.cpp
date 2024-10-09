/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:25:07 by likong            #+#    #+#             */
/*   Updated: 2024/10/09 09:33:43 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("empty"){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
}

Character::Character(const std::string &name): _name(name){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
}

Character::Character(const Character &other): _name(other._name){
	for (int i = 0; i < 4; i++){
		if (other._inventory[i] == nullptr)
			this->_inventory[i] = nullptr;
		else
			this->_inventory[i] = other._inventory[i]->clone();
	}
}

Character::~Character(){
	for(int i = 0; i < 4; i++){
		delete this->_inventory[i];
		this->_inventory[i] = nullptr;
	}
}

Character	&Character::operator = (const Character &other){
	if (this == &other)
		return (*this);
	this->_name = other._name;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] != nullptr){
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}
		if (other._inventory[i] == nullptr)
			this->_inventory[i] = nullptr;
		else
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

std::string const	&Character::getName() const{
	return (this->_name);
}

void	Character::equip(AMateria *m){
	if (m == nullptr)
		return ;
	std::cout << "hello" << std::endl;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] == nullptr){
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx){
	if (idx < 0 || idx > 3)
		return ;
	else if (this->_inventory[idx] == nullptr)
		return ;
	else
		this->_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter &target){
	if (idx < 0 || idx > 3)
		return ;
	else if (this->_inventory[idx] != nullptr)
		this->_inventory[idx]->use(target);
}

AMateria	*Character::getInventory(int idx){
	if (idx < 0 || idx > 3)
		return (nullptr);
	return (this->_inventory[idx]);
}
