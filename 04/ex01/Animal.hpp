/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:16:20 by likong            #+#    #+#             */
/*   Updated: 2024/10/04 11:41:34 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal{
	protected:
		std::string	_type;
	
	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();
		
		Animal			&operator = (const Animal &other);
		
		std::string		getType() const;
		virtual	void	makeSound() const;
};
