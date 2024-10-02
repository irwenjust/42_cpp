/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:42:05 by likong            #+#    #+#             */
/*   Updated: 2024/09/26 19:11:53 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	_name;
		
	public:
		Zombie(std::string name);
		~Zombie(void);
		
		void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
