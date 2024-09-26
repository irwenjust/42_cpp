/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:21:30 by likong            #+#    #+#             */
/*   Updated: 2024/09/25 19:52:12 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Tool.hpp"


int	main(int argc, char **argv){
	(void)argv;
	
	std::string	input;
	PhoneBook	phoneBook;
	if (argc != 1){
		std::cout << "Invalid argument, please wait" << std::endl;
		return 1;
	}
	while (1){
		std::cout << "\033[38;2;129;242;83m" << "Choice a command(ADD/SEARCH/EXIT): " << "\033[0m";
		if (!std::getline(std::cin, input))
			checkFailStatus();
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact(phoneBook);
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Invalid input\n";
	}
	return 0;
}