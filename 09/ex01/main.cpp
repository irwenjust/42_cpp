#include <iostream>

#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Use: ./RPN [inverted Polish mathematical expression]\n";
		return 1;
	}

	try {
		RPN(std::string(argv[1]));
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}