#pragma once

# include <stack>
# include <string>
# include <iostream>
# include <sstream>
# include <algorithm>

class RPN {
	public:
		RPN() = delete;
		RPN(const RPN&)  = delete;
		RPN(std::string t_inputString);
		~RPN() = default;

		RPN& operator=(const RPN&)  = delete;

		class ArgumentException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	
	private:
		std::stack<double> m_stack {};

		void performCalculation(char t_operator);
};