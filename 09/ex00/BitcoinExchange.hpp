/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:06 by likong            #+#    #+#             */
/*   Updated: 2025/10/21 12:03:43 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <map>

class BitcoinExchange {
    public:
        BitcoinExchange() = default;
        BitcoinExchange(BitcoinExchange &other) = default;
        BitcoinExchange &operator=(BitcoinExchange &other) = default;
        ~BitcoinExchange() = default;

        void parseData();
        double getPrice(const std::string &date) const;
        void parseInput(std::string &file);

    private:
        std::map<std::string, double> _priceData;
};
