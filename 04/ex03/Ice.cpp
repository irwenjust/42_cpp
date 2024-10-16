/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:23:31 by likong            #+#    #+#             */
/*   Updated: 2024/10/09 11:29:41 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){}

Ice::Ice(const Ice &): AMateria("ice"){}

Ice::~Ice(){}

Ice	&Ice::operator = (const Ice &){
	return (*this);
}

AMateria	*Ice::clone() const{
	return (new Ice());
}

void	Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at "
			<< target.getName() << " *\n";
}
