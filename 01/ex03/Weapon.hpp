/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:55:27 by likong            #+#    #+#             */
/*   Updated: 2024/09/27 08:50:37 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon{
	private:
		std::string	_type;
	
	public:
		Weapon(std::string typeName);
		std::string const	&getType(void);
		void				setType(std::string type);
};
