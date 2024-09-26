/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:34:16 by likong            #+#    #+#             */
/*   Updated: 2024/09/24 20:32:09 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

static std::string	toUpper(char *str){
	std::string	upperStr = str;
	for (char &c : upperStr)
		c = std::toupper(static_cast<unsigned char>(c));
	return (upperStr);
}

int	main(int argc, char **argv){
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else{
		for (int i = 1; i < argc; i++)
			std::cout << toUpper(argv[i]);
		std::cout << std::endl;
	}
	return 0;
}
