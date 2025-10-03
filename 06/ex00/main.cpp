#include <iostream>
#include "ScalarConverter.hpp"

#define BLUE "\033[34m"
#define WHITE "\033[0m"

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		const std::string input(argv[1]);
		ScalarConverter::convert(input);
		return (0);
	}

	std::cout << BLUE << "\n----------Test----------\n\n" << WHITE;
	
	std::cout << BLUE << "\n----------Char Test----------\n\n" << WHITE;
	std::cout << BLUE << "\n---Input: [a]---\n\n" << WHITE;
	ScalarConverter::convert("a");
	std::cout << BLUE << "\n---Input: [A]---\n\n" << WHITE;
	ScalarConverter::convert("A");
	std::cout << BLUE << "\n---Input: [0]---\n\n" << WHITE;
	ScalarConverter::convert("0");
	std::cout << BLUE << "\n---Input: [ ]---\n\n" << WHITE;
	ScalarConverter::convert(" ");
	std::cout << BLUE << "\n---Input: [\\n]---\n\n" << WHITE;
	ScalarConverter::convert("\n");
	std::cout << BLUE << "\n---Input: [\\t]---\n\n" << WHITE;
	ScalarConverter::convert("\t");
	std::cout << BLUE << "\n---Input: [+]---\n\n" << WHITE;
	ScalarConverter::convert("+");
	std::cout << BLUE << "\n---Input: [&]---\n\n" << WHITE;
	ScalarConverter::convert("&");
	std::cout << BLUE << "\n---Input: [string]---\n\n" << WHITE;
	ScalarConverter::convert("string");
	std::cout << BLUE << "\n---Input: [+++]---\n\n" << WHITE;
	ScalarConverter::convert("+++");
	std::cout << BLUE << "\n---Input: [😀]--\n\n" << WHITE;	
	ScalarConverter::convert("😀");

	return (0);
}
