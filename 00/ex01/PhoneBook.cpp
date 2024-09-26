/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:47:42 by likong            #+#    #+#             */
/*   Updated: 2024/09/26 09:54:48 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Tool.hpp"

PhoneBook::PhoneBook()
		: _amount(0), _oldestContact(0){}

std::string	PhoneBook::limitStr(const std::string &str){
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::displayAll(){
	std::cout << std::right;
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "FirstName" << "|"
				<< std::setw(10) << "LastName" << "|"
				<< std::setw(10) << "NickName" << std::endl;
	for (int i = 0; i < _amount; i++){
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << limitStr(contacts[i].getFirstName()) << "|"
				<< std::setw(10) << limitStr(contacts[i].getLastName()) << "|"
				<< std::setw(10) << limitStr(contacts[i].getNickName()) << std::endl;
	}
}

void	PhoneBook::getContact(int index){
	if (index < _amount && index >= 0)
		contacts[index].printContact();
	else
		std::cout << "Invalid input. Please try another index number\n";
}

void	PhoneBook::searchContact(PhoneBook &phoneBook){
	if (_amount == 0){
		std::cout << "The phoneBook is empty right now\n";
		return ;
	}
	phoneBook.displayAll();
	int	index = findIndex();
	if (index != -1)
		phoneBook.getContact(index);
}

void	PhoneBook::addContact(){
	std::string	input;
	Contact		newContact;
	
	for (int i = 0; i < 5; i++){
		newContact.printPrompt(i);
		if (!std::getline(std::cin, input))
			checkFailStatus();
		if (input == ""){
			std::cout << "The content cannot be empty, please input again\n";
			i--;
			continue ;
		}
		else
			newContact.addContent(i, input);
	}
	contacts[_oldestContact] = newContact;
	if (_amount < 8)
		_amount++;
	_oldestContact++;
	if (_oldestContact == 8)
		_oldestContact = 0;
}
