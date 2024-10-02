/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:19:23 by likong            #+#    #+#             */
/*   Updated: 2024/09/30 10:34:27 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replaceFile.hpp"

int	main(int argc, char **argv){
	if (argc != 4){
		std::cout << "The argument must follow as: ./sed filename s1 s2\n";
		return 1;
	}
	std::string	fileName = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	ReplaceFile	replace(fileName, s1, s2, "");
	if (replace.replace())
		return 1;
	return 0;
}
