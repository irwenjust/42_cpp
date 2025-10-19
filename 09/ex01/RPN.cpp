#include "RPN.hpp"

// CONSTRUCTOR

RPN::RPN(std::string t_inputString) {
	std::stringstream sstream(t_inputString);
	std::string arg;
	std::string rpn_operators("+-*/");

	if (t_inputString.empty())
		throw ArgumentException();
	while (getline(sstream, arg, ' ')) {
		if (arg.length() != 1)
			throw ArgumentException();

		if (std::isdigit(arg[0]))
			m_stack.push(std::stoi(arg));
		else if (std::find(rpn_operators.begin(), rpn_operators.end(), arg[0]) != rpn_operators.end())
			performCalculation(arg[0]);
		else
			throw ArgumentException();
	}

	if (m_stack.size() > 1)
		throw ArgumentException();

	std::cout << m_stack.top() << "\n";
}

// MEMBER FUNCTIONS

void RPN::performCalculation(char t_operator) {
	double var1;
	double var2;
	double result;

	if (m_stack.size() < 2)
		throw ArgumentException();

	var2 = m_stack.top();
	m_stack.pop();
	var1 = m_stack.top();
	m_stack.pop();

	switch (t_operator) {
		case '+':
			result = var1 + var2;
			break;
		case '-':
			result = var1 - var2;
			break;
		case '*':
			result = var1 * var2;
			break;
		case '/':
			result = var1 / var2;
			break;
	}

	m_stack.push(result);
}

// EXCEPTIONS

const char* RPN::ArgumentException::what() const throw() {
	return "Error";
}
