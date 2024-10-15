/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:26:00 by likong            #+#    #+#             */
/*   Updated: 2024/10/09 18:59:36 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &other){
	for (int i = 0; i < 4; i++){
		if (other._inventory[i] == nullptr)
			this->_inventory[i] = nullptr;
		else
			this->_inventory[i] = other._inventory[i]->clone();
	}
}

MateriaSource::~MateriaSource(){
	void*	freeObjects[4] = {nullptr};
	int		freeCount = 0;

	for (int i = 0; i < 4; i++)
	{
		int	checkFree = 0;
		for (int j = 0; j < freeCount; j++)
		{
			if (this->_inventory[i] == freeObjects[j])
			{
				checkFree = 1;
				break;
			}
		}
		if (!checkFree)
		{
			freeObjects[freeCount] = this->_inventory[i];
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
			freeCount++;
		}
	}
}

MateriaSource	&MateriaSource::operator = (const MateriaSource &other){
	if (this == &other)
		return (*this);
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

void	MateriaSource::learnMateria(AMateria *m){
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] == nullptr){
			this->_inventory[i] = m;
			return ;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
			return ;
	}
	delete m;
	m = nullptr;
}

AMateria	*MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] != nullptr
			&& this->_inventory[i]->getType() == type){
				return (this->_inventory[i]->clone());
			}
	}
	return (nullptr);
}
