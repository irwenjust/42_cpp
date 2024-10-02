/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:42:49 by likong            #+#    #+#             */
/*   Updated: 2024/09/30 11:44:47 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Harl{
	private:
		std::string	_level[5];
		void		(Harl::*_harlFunc[5])(void);
		void		_debug(void);
		void		_info(void);
		void		_warning(void);
		void		_error(void);
		void		_others(void);
	
	public:
		Harl(void);
		void	complain(std::string level);
		~Harl(void);
};
