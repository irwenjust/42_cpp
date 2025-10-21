/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:55:04 by likong            #+#    #+#             */
/*   Updated: 2025/10/21 11:55:04 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string t_inputString) {
	std::stringstream sstream(t_inputString);
	std::string arg;
	std::string rpn_operators("+-*/");

	if (t_inputString.empty())
		throw ArgumentException();
	while (sstream >> arg) {
		if (arg.length() != 1)
			throw ArgumentException();

		if (arg.size() == 1 && std::isdigit(static_cast<unsigned char>(arg[0])))
			m_stack.push(std::stoi(arg));
		else if (std::find(rpn_operators.begin(), rpn_operators.end(), arg[0]) != rpn_operators.end())
			performCalculation(arg[0]);
		else
			throw ArgumentException();
	}

	if (m_stack.size() != 1)
		throw ArgumentException();

	std::cout << m_stack.top() << "\n";
}

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
			if (var2 == 0)
				throw ArgumentException();
			result = var1 / var2;
			break;
	}

	m_stack.push(result);
}

const char* RPN::ArgumentException::what() const throw() {
	return "Error";
}
