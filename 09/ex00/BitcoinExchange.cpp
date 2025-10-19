#include "BitcoinExchange.hpp"

bool checkDate(std::string dateString)
{
	std::string segment;
	std::stringstream dateStringStream(dateString);
	int dateInt;
	int year;
	int month;
    // std::cout << "date string: " << dateInt << std::endl;

	for (int i = 0; i < 3; i++)
	{
		getline(dateStringStream, segment, '-');
		dateInt = std::stoi(segment);

		switch (i)
		{
			case 0:
				if (dateInt < 2009 || segment.length() > 4)
					return false;
				year = dateInt;
				break;
			case 1:
				if (dateInt < 1 || dateInt > 12  || segment.length() > 2)
					return false;
				month = dateInt;
				break;
			case 2:
				if (dateInt < 1 || dateInt > 31  || segment.length() > 2)
					return false;
				if ((month == 4 || month == 6 || month == 9 || month == 11) && dateInt > 30)
					return false;
				if (month == 2 && dateInt > 29)
					return false;
				if (month == 2 && dateInt > 28)
				{
					if (year % 4 != 0)
						return false;
					if (year % 100 == 0 && year % 400 != 0)
						return false;
				}
				break;
		}
	}

	if (getline(dateStringStream, segment, '-'))
		return false;

	return true;
}


void BitcoinExchange::parseData() {
    const std::string dataFilePath = "./data.csv";
    std::ifstream dataFile(dataFilePath);
    if (!dataFile.is_open())
        throw std::runtime_error("Error: Could not open file " + dataFilePath);

    std::string line;
    std::smatch matches;
    // YYYY-MM-DD,value
    std::regex linePattern(R"(^(\d{4}-\d{2}-\d{2}),([+]?(?:\d+\.?\d*|\.\d+))$)");
    while (getline(dataFile, line)) {
        if (line == "date,exchange_rate" || line.empty())
            continue;
        if (std::regex_match(line, matches, linePattern)) {
            std::string date = matches[1].str();
            double price = std::stod(matches[2].str());
            if (_priceData.find(date) != _priceData.end())
                throw std::runtime_error("duplicate data, fix your data");
            _priceData[date] = price;
        }
    }
}

double BitcoinExchange::getPrice(const std::string &date) const {
    auto it = _priceData.find(date);
    if (it != _priceData.end())
        return it->second;

    it = _priceData.lower_bound(date);
    if (it == _priceData.begin() && date < it->first)
        throw std::runtime_error("Error: no data for date " + date);

    if (it == _priceData.end() || date < it->first)
        --it;

    return it->second;
}

void BitcoinExchange::parseInput(std::string &file)
{
    std::ifstream inputFile(file);
    if (!inputFile.is_open())
        throw std::runtime_error("Error: Could not open file " + file);

    std::string line;
    std::smatch matches;
    // YYYY-MM-DD | coins
    std::regex linePattern(R"(^(\d{4}-\d{2}-\d{2}) \| ([-+]?(?:\d+\.?\d*|\.\d+))$)");
    while (getline(inputFile, line)) {
        if (line == "date | value" || line.empty())
            continue;
        if (std::regex_match(line, matches, linePattern)) {
            std::string date = matches[1].str();
            try {
                if (!checkDate(date)) {
                    std::cout << "Error: Date range is not followed" << " => " << date << std::endl;
                    continue ;
                }
                double coins = std::stod(matches[2].str());
                if (coins < 0) {
                    std::cout << "Error: not a positive number" << " => " << coins << std::endl;
                    continue;
                }
                if (coins > 1000) {
                    std::cout << "Error: too large a number." << " => " << coins << std::endl;
                    continue;
                }
                try {
                    double price = getPrice(date);
                    double sum = coins * price;
                    std::cout << date << " => " << price << " * " << coins << " = " << sum
                              << std::endl;
                }
                catch (const std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
            }
            catch (const std::exception &e) {
                std::cout << "Error: invalid number format." << std::endl;
            }
        }
        else {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
}

