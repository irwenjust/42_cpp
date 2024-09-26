/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:29:07 by likong            #+#    #+#             */
/*   Updated: 2024/09/26 09:53:49 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	: _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret(""){}

std::string	Contact::getFirstName(){
	return (_firstName);
}

std::string	Contact::getLastName(){
	return (_lastName);
}

std::string	Contact::getNickName(){
	return (_nickName);
}

void	Contact::addContent(int i, std::string &str){
	switch (i)
	{
		case FIRSTNAME:
			_firstName = str;
			break ;
		case LASTNAME:
			_lastName = str;
			break ;
		case NICKNAME:
			_nickName = str;
			break ;
		case PHONENUMBER:
			_phoneNumber = str;
			break ;
		case DARKESTSECRET:
			_darkestSecret = str;
			break ;
		default:
			std::cout << "Invalid field\n";
			break ;
	}
}

void	Contact::printPrompt(int i){
	std::cout << std::left;
	switch (i)
	{
		case FIRSTNAME:
			std::cout << std::setw(15) << "FirstName: ";
			break ;
		case LASTNAME:
			std::cout << std::setw(15) << "LastName: ";
			break ;
		case NICKNAME:
			std::cout << std::setw(15) << "Nickname: ";
			break ;
		case PHONENUMBER:
			std::cout << std::setw(15) << "PhoneNumber: ";
			break ;
		case DARKESTSECRET:
			std::cout << std::setw(15) << "DarkestSecret: ";
			break ;
		default:
			std::cout << "Invalid field\n";
			break ;
	}
}

void	Contact::printContact(){
	std::cout << std::left;
	std::cout << std::setw(15) << "FirstName: " << _firstName << std::endl;
	std::cout << std::setw(15) << "LastName: " << _lastName << std::endl;
	std::cout << std::setw(15) << "Nickname: " << _nickName << std::endl;
	std::cout << std::setw(15) << "PhoneNumber: " << _phoneNumber << std::endl;
	std::cout << std::setw(15) << "DarkestSecret: " << _darkestSecret << std::endl;
}
