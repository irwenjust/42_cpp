/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:55:11 by likong            #+#    #+#             */
/*   Updated: 2025/10/21 11:55:13 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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