/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:16:52 by likong            #+#    #+#             */
/*   Updated: 2024/10/04 11:57:23 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal{
	public:
		Dog();
		Dog(const Dog &other);
		~Dog() override;
		
		Dog		&operator = (const Dog &other);

		void	makeSound() const override;
};
