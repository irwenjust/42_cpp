#pragma once

# include <stack>
# include <string>
# include <iostream>
# include <sstream>
# include <algorithm>

class RPN {
	public:
		RPN(std::string t_inputString);
		~RPN(void) = default;

		class ArgumentException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	
	private:
		RPN(void) = delete;
		RPN(const RPN&)  = delete;
		RPN& operator=(const RPN&)  = delete;

		void performCalculation(char t_operator);

		std::stack<double> m_stack {};
};