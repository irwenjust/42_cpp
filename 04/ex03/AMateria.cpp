/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:22:02 by likong            #+#    #+#             */
/*   Updated: 2024/10/07 20:51:10 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): _type(type){}

std::string const	&AMateria::getType() const{
	return (this->_type);
}

void	AMateria::use(ICharacter &target){
	std::cout << "The character " << target.getName() << " use "
			<< this->_type << " of Amateria type\n";
}
