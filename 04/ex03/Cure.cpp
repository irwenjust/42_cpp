/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:23:51 by likong            #+#    #+#             */
/*   Updated: 2024/10/09 09:45:22 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure"){}

Cure::Cure(const Cure &): AMateria("cure"){}

Cure::~Cure(){}

Cure	&Cure::operator = (const Cure &){
	return (*this);
}

AMateria	*Cure::clone() const{
	return (new Cure());
}

void	Cure::use(ICharacter &target){
	std::cout << "* heals "<< target.getName() <<"'s wounds *\n";
}
