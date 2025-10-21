/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:53:54 by likong            #+#    #+#             */
/*   Updated: 2025/10/21 11:53:54 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include <chrono>
# include <vector>
# include <list>
# include <ranges>

class PmergeMe {
	public:
        PmergeMe(void) = delete;
		PmergeMe(const PmergeMe&) = delete;
		PmergeMe(size_t argc, char *argv[]);
		~PmergeMe() = default;

        PmergeMe& operator=(const PmergeMe&) = delete;
		
		class ArgumentException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
        std::vector<int> m_vec {};
		std::list<int> m_list {};
		std::chrono::microseconds m_vecSortTime;
		std::chrono::microseconds m_listSortTime;

		void printVector(std::string t_pretext);
		void printList(std::string t_pretext);

		void sortVector(std::vector<int>& container);
		void sortList(std::list<int>& container);
};
