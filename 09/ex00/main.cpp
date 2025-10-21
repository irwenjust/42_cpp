/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:02:51 by likong            #+#    #+#             */
/*   Updated: 2025/10/21 12:06:14 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::string inputFile;
    if (argc == 2) {
        inputFile = argv[1];
    }
    else {
        std::cout << "Error: could not open file.\n";
        return 1;
    }
    try {
        BitcoinExchange btc;
        btc.parseData();
        btc.parseInput(inputFile);
        return 0;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}