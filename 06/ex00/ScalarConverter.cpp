#include "ScalarConverter.hpp"

static bool isChar(const std::string &str)
{
	return (str.length() == 1 && !std::isdigit(str[0]));
}

static bool isInt(const std::string &str)
{
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.size())
	{
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

static bool isFloat(const std::string &str)
{
	int dot = 0;
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.size() - 1)
	{
		if (str[i] == '.')
			dot++;
		else if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return (dot == 1 && (str[i] == 'f' || str[i] == 'F'));
}

static bool isDouble(const std::string &str)
{
	int dot = 0;
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.size())
	{
		if (str[i] == '.')
			dot++;
		else if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return (dot == 1);
}

static bool isPseudoFloat(const std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
		return (true);
	return (false);
}

static bool isPseudoDouble(const std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "nan" || str == "inf")
		return (true);
	return (false);
}

static int getType(const std::string &str)
{
	if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if (isFloat(str))
		return FLOAT;
	else if (isDouble(str))
		return DOUBLE;
	else if (isPseudoFloat(str))
		return PSEUDOFLOAT;
	else if (isPseudoDouble(str))
		return PSEUDODOUBLE;
	else
		return UNKNOWN;
}

static void convertNumber(const std::string &str, int type)
{
	try {
		size_t idx;
		double value = std::stod(str, &idx); // throws on invalid or out-of-range
		if (type != FLOAT && idx != str.length())
			throw std::invalid_argument("invalid input");
		if(type == FLOAT && (idx != str.length() - 1))
			throw std::invalid_argument("invalid input");

		// toChar
		if (value >= std::numeric_limits<unsigned char>::min() && value <= std::numeric_limits<unsigned char>::max())
		{
			if (isprint(static_cast<unsigned char>(value)))
				std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;

		// toInt
		if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;

		// toFloat
		if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::fixed << std::setprecision(1)
					  << static_cast<float>(value) << "f" << std::endl;

		// toDouble
		std::cout << "double: " << std::fixed << std::setprecision(1)
				  << static_cast<double>(value) << std::endl;

	} catch (const std::invalid_argument& e) {
		std::cout << "Conversion error: invalid input" << std::endl;
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "Conversion error: input out of range" << std::endl;
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &str) {
    if (str.empty()) {
        std::cout << "Input is empty" << std::endl;
        return ;
    }
    int type = getType(str);
    switch (type) {
    case CHAR:
        std::cout << "char: '" << str[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0])  << std::endl;
		std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" << std::endl;
		std::cout << "doublcd e: "  << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
        break;
    case PSEUDOFLOAT:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
		break;
	case PSEUDODOUBLE:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		break;
	case UNKNOWN:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		break;
	case INT:
    case FLOAT:
    case DOUBLE:
		convertNumber(str, type);
		break;
    default:
        break;
    }
}
