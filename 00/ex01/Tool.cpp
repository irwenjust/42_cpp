/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:18:48 by likong            #+#    #+#             */
/*   Updated: 2024/09/26 09:39:08 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tool.hpp"

void	checkFailStatus(){
	if (std::cin.eof())
		std::cout << "End by eof(signal)\n";
	else
		std::cout << "find some error from input or others\n";
	exit(1);
}

int	findIndex(){
	std::string	input;
	int			index;

	std::cout << "\033[38;2;129;242;83m" << "Enter the index number: " << "\033[0m";
	if (!std::getline(std::cin, input))
		checkFailStatus();
	if (input.length() < 4){
		for (size_t i = 0; i < input.length(); i++){
			if (!std::isdigit(input[i])){
				std::cout << "Invalid input. Only allow number\n";
				return (-1);
			}	
		}
		std::istringstream	iss(input);
		iss >> index;
		return (index);
	}
	std::cout << "Invalid input. It is sooooo long\n";
	return (-1);
}
