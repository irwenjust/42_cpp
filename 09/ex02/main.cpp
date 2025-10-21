/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:54:00 by likong            #+#    #+#             */
/*   Updated: 2025/10/21 11:54:29 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Use: ./PmergeMe [positive integer sequence]\n";
		return 1;
	}

	try {
		argv++;
		argc--;
		PmergeMe merge(argc, argv);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}