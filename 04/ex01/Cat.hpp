/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:16:37 by likong            #+#    #+#             */
/*   Updated: 2024/10/07 16:42:45 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
	private:
		Brain	*_brain;
	public:
		Cat();
		Cat(const Cat &other);
		~Cat() override;
		
		Cat		&operator = (const Cat &other);

		void	makeSound() const override;
};
