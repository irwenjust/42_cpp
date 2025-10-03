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

	std::cout << "\n----------Test----------\n\n";
	
	std::cout << "\n----------Char Test----------\n\n";
	std::cout << "\n---Input: [a]---\n\n";
	ScalarConverter::convert("a");
	std::cout << "\n---Input: [A]---\n\n";
	ScalarConverter::convert("A");
	std::cout << "\n---Input: [0]---\n\n";
	ScalarConverter::convert("0");
	std::cout << "\n---Input: [ ]---\n\n";
	ScalarConverter::convert(" ");
	std::cout << "\n---Input: [\\n]---\n\n";
	ScalarConverter::convert("\n");
	std::cout << "\n---Input: [\\t]---\n\n";
	ScalarConverter::convert("\t");
	std::cout << "\n---Input: [+]---\n\n";
	ScalarConverter::convert("+");
	std::cout << "\n---Input: [&]---\n\n";
	ScalarConverter::convert("&");
	std::cout << "\n---Input: [string]---\n\n";
	ScalarConverter::convert("string");
	std::cout << "\n---Input: [+++]---\n\n";
	ScalarConverter::convert("+++");
	std::cout << "\n---Input: [😀]--\n\n";	
	ScalarConverter::convert("😀");

	std::cout << "\n----------Int Test----------\n\n";
	std::cout << "\n---Input: [4]---\n\n";
	ScalarConverter::convert("4");
	std::cout << "\n---Input: [+42]---\n\n";
	ScalarConverter::convert("+42");
	std::cout << "\n---Input: [-42]---\n\n";
	ScalarConverter::convert("-42");
	std::cout << "\n---Input: [4242]---\n\n";
	ScalarConverter::convert("4242");
	std::cout << "\n---Input: [INT_MAX]---\n\n";
	ScalarConverter::convert("2147483647");
	std::cout << "\n---Input: [INT_MIN]---\n\n";
	ScalarConverter::convert("-2147483648");
	std::cout << "\n---Input: [INT_MAX + 1]---\n\n";
	ScalarConverter::convert("2147483648");
	std::cout << "\n---Input: [INT_MIN - 1]---\n\n";
	ScalarConverter::convert("-2147483649");
	std::cout << "\n---Input: [++42]---\n\n";
	ScalarConverter::convert("++42");
	std::cout << "\n---Input: [+42a]---\n\n";
	ScalarConverter::convert("+42a");

	std::cout << "\n----------Float Test----------\n\n";
	std::cout << "\n---Input: [0.0f]---\n\n";
	ScalarConverter::convert("0.0f");
	std::cout << "\n---Input: [+4.2f]---\n\n";
	ScalarConverter::convert("+4.2f");
	std::cout << "\n---Input: [-42.0f]---\n\n";
	ScalarConverter::convert("-42.0f");
	std::cout << "\n---Input: [424.2f]---\n\n";
	ScalarConverter::convert("424.2f");
	std::cout << "\n---Input: [nanf]---\n\n";
	ScalarConverter::convert("nanf");
	std::cout << "\n---Input: [-inff]---\n\n";
	ScalarConverter::convert("-inff");
	std::cout << "\n---Input: [+inff]---\n\n";
	ScalarConverter::convert("+inff");
	std::cout << "\n---Input: [FLOAT_MAX]---\n\n";
	float floatMax = std::numeric_limits<float>::max();
	std::string floatMaxStr = std::to_string(floatMax);
	ScalarConverter::convert(floatMaxStr);
	std::cout << "\n---Input: [FLOAT_MIN]---\n\n";
	float floatMin = std::numeric_limits<float>::lowest();
	std::string floatMinStr = std::to_string(floatMin);
	ScalarConverter::convert(floatMinStr);
	std::cout << "\n---Input: [FLOAT_OVERFLOW]---\n\n";
	std::string floatOverFlowStr = std::to_string(floatMax * 2.0f);
	ScalarConverter::convert(floatOverFlowStr);
	std::cout << "\n---Input: [FLOAT_OVERFLOW_NEG]---\n\n";
	std::string floatNegOverFlowStr = std::to_string(floatMin * 2.0f);
	ScalarConverter::convert(floatNegOverFlowStr);
	std::cout << "\n---Input: [42.f]---\n\n";
	ScalarConverter::convert("42.f");
	std::cout << "\n---Input: [42f.]---\n\n";
	ScalarConverter::convert("42f.");
	std::cout << "\n---Input: [.42f]---\n\n";
	ScalarConverter::convert(".42f");
	std::cout << "\n---Input: [42.4.2f]---\n\n";
	ScalarConverter::convert("42.4.2f");
	std::cout << "\n---Input: [4.2ff]---\n\n";
	ScalarConverter::convert("4.2ff");

	std::cout << "\n----------Double Test----------\n\n";
	std::cout << "\n---Input: [0.0]---\n\n";
	ScalarConverter::convert("0.0");
	std::cout << "\n---Input: [+4.2]---\n\n";
	ScalarConverter::convert("+4.2");
	std::cout << "\n---Input: [-42.0]---\n\n";
	ScalarConverter::convert("-42.0");
	std::cout << "\n---Input: [0.42]---\n\n";
	ScalarConverter::convert("0.42");
	std::cout << "\n---Input: [424.2]---\n\n";
	ScalarConverter::convert("424.2");
	std::cout << "\n---Input: [nan]---\n\n";
	ScalarConverter::convert("nan");
	std::cout << "\n---Input: [-inf]---\n\n";
	ScalarConverter::convert("-inf");
	std::cout << "\n---Input: [+inf]---\n\n";
	ScalarConverter::convert("+inf");
	std::cout << "\n---Input: [DOUBLE_MAX]---\n\n";
	double doubleMax = std::numeric_limits<double>::max();
	std::string doubleMaxStr = std::to_string(doubleMax);
	ScalarConverter::convert(doubleMaxStr);
	std::cout << "\n---Input: [DOUBLE_MIN]---\n\n";
	double doubleMin = std::numeric_limits<double>::lowest();
	std::string doubleMinStr = std::to_string(doubleMin);
	ScalarConverter::convert(doubleMinStr);
	std::cout << "\n---Input: [DOUBLE_OVERFLOW]---\n\n";
	std::string doubleOverFlowStr = std::to_string(doubleMax * 2.0);
	ScalarConverter::convert(doubleOverFlowStr);
	std::cout << "\n---Input: [DOUBLE_OVERFLOW_NEG]---\n\n";
	std::string doubleNegOverFlowStr = std::to_string(doubleMin * 2.0);
	ScalarConverter::convert(doubleNegOverFlowStr);
	std::cout << "\n---Input: [214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647.0]---\n\n";
	ScalarConverter::convert("214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647214547483647.0");
	std::cout << "\n---Input: [42.]---\n\n";
	ScalarConverter::convert("42.");
	std::cout << "\n---Input: [.42]---\n\n";
	ScalarConverter::convert(".42");
	std::cout << "\n---Input: [42.4.2]---\n\n";
	ScalarConverter::convert("42.4.2");
	std::cout << "\n---Input: [42..42]---\n\n";
	ScalarConverter::convert("42..42");

	return (0);
}
