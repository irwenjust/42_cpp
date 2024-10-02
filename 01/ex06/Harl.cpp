/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:42:54 by likong            #+#    #+#             */
/*   Updated: 2024/09/30 12:43:32 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){
	this->_level[0] = "DEBUG";
	this->_level[1] = "INFO";
	this->_level[2] = "WARNING";
	this->_level[3] = "ERROR";
	this->_harlFunc[0] = &Harl::_debug;
	this->_harlFunc[1] = &Harl::_info;
	this->_harlFunc[2] = &Harl::_warning;
	this->_harlFunc[3] = &Harl::_error;
}

Harl::~Harl(void){}

void	Harl::_debug(void){
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple"
				<< "-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void	Harl::_info(void){
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put"
				<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::_warning(void){
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for"
				<< "years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::_error(void){
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::_others(void){
	std::cout << "This is unexpect level." << std::endl;
}

void	Harl::complain(std::string level){
	int	i = 0;
	while (i < 5 && level != this->_level[i])
		i++;
	switch (i)
	{
	case 0:
		_debug();
		_info();
		_warning();
		_error();
		break;
	case 1:
		_info();
		_warning();
		_error();
		break;
	case 2:
		_warning();
		_error();
		break;
	case 3:
		_error();
		break;
	default:
		_others();
		break;
	}
}
