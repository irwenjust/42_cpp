/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:42:29 by likong            #+#    #+#             */
/*   Updated: 2024/09/30 12:44:52 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv){
	(void)argv;
	if (argc != 2){
		std::cout << "Invalid argument. Please write correct level.\n";
		return 1;
	}
	Harl	harl;
	harl.complain(argv[1]);
	return 0;
}
