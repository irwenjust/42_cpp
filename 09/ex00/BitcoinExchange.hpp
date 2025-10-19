#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <map>

class BitcoinExchange
{
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
