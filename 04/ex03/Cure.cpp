/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:23:51 by likong            #+#    #+#             */
/*   Updated: 2024/10/08 09:28:25 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("Cure"){}

Cure::Cure(const Cure &): AMateria("Cure"){}

Cure::~Cure(){}

Cure	&Cure::operator = (const Cure &){
	return (*this);
}

AMateria	*Cure::clone() const{
	return (new Cure());
}

void	Cure::use(ICharacter &target){
	std::cout << "* shoots an Cure bolt at "
			<< target.getName() << std::endl;
}
