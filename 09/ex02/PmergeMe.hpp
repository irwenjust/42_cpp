#pragma once

# include <string>
# include <iostream>
# include <chrono>
# include <vector>
# include <list>

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
		void sortVector();
		void sortList();
};
