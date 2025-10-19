#include "PmergeMe.hpp"

// HELPER DECLARATIONS

static bool strIsDigit(std::string str);
static void printIntPairVector(std::vector<std::pair<int, int>> vector);
static void printIntPairList(std::list<std::pair<int, int>> list);

// CONSTRUCTOR

PmergeMe::PmergeMe(size_t argc, char *argv[]) {
	for (size_t i = 0; i < argc; i++) {
		int argInt;
		std::string argStr(argv[i]);
		
		if (!strIsDigit(argStr))
			throw ArgumentException();
		try {
			argInt = std::stoi(argStr);
		}
		catch(const std::exception& e) {
			throw ArgumentException();
		}

		m_vec.push_back(argInt);
		m_list.push_back(argInt);
	}

	printVector("Before:\t");

	auto startTime = std::chrono::high_resolution_clock::now();
	sortVector();
	auto stopTime = std::chrono::high_resolution_clock::now();
	m_vecSortTime = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

	startTime = std::chrono::high_resolution_clock::now();
	sortList();
	stopTime = std::chrono::high_resolution_clock::now();
	m_listSortTime = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

	for (size_t i = 0; i < m_vec.size(); i++) {
		if (m_vec[i] != *(std::next(m_list.begin(), i)))
			throw std::runtime_error("Failed to sort lists");
	}

	printVector("After:\t");

	std::cout << "Time to process a range of " << m_vec.size() 
				<< " elements with std::vector : " << m_vecSortTime.count() << "us\n";
	std::cout << "Time to process a range of " << m_list.size() 
				<< " elements with std::list : " << m_listSortTime.count() << "us\n";
}

// MEMBER FUNCTIONS

void PmergeMe::printVector(std::string t_pretext) {
	std::cout << t_pretext;
	for (size_t i = 0; i < m_vec.size(); i++) {
		if (i != 0)
			std::cout << " ";
		std::cout << m_vec[i];
	}
	std::cout << "\n";
}

void PmergeMe::printList(std::string t_pretext) {
	std::cout << t_pretext;
	for (size_t i = 0; i < m_list.size(); i++) {
		if (i != 0)
			std::cout << " ";
		std::cout << *(std::next(m_list.begin(), i));
	}
	std::cout << "\n";
}

void PmergeMe::sortVector() {
	if (m_vec.size() == 1)
		return ;

	std::vector<std::pair<int, int>> pairs;
	int oddInt = -1;

	for (size_t i = 0; i + 1 < m_vec.size(); i += 2)
		pairs.push_back(std::pair<int, int>(m_vec[i], m_vec[i + 1]));
	if (m_vec.size() % 2 == 1)
		oddInt = m_vec.back();

	m_vec.clear();

	for (std::pair<int, int>& pair : pairs) {
		if (pair.second < pair.first)
			std::swap(pair.first, pair.second);
		m_vec.push_back(pair.second);
	}
	if (oddInt != -1)
		m_vec.push_back(oddInt);

	// std::cout << "pairs: ";
	printIntPairVector(pairs);

	// printVector("m_vec:\t");

	sortVector();

	for (std::pair<int, int>& pair : pairs) {
		std::vector<int>::iterator it = m_vec.begin();
		while (*it < pair.first)
			it++;
		m_vec.insert(it, pair.first);
	}

	// printVector("m_vec sorted:\t");
}

void PmergeMe::sortList() {
	if (m_list.size() == 1)
		return ;

	std::list<int>::iterator it = m_list.begin();
	std::list<std::pair<int, int>> pairs;
	int oddInt = -1;

	for (size_t i = 0; i + 1 < m_list.size(); i += 2) {
		pairs.push_back(std::pair<int, int>(*it, *(std::next(it))));
		it = std::next(it, 2);
	}
	if (m_list.size() % 2 == 1)
		oddInt = m_list.back();

	m_list.clear();

	for (std::pair<int, int>& pair : pairs) {
		if (pair.second < pair.first)
			std::swap(pair.first, pair.second);
		m_list.push_back(pair.second);
	}
	if (oddInt != -1)
		m_list.push_back(oddInt);
	
	// std::cout << "pairs: ";
	printIntPairList(pairs);

	// printList("m_list:\t");
	
	sortList();

	for (std::pair<int, int>& pair : pairs) {
		it = m_list.begin();
		while (*it < pair.first)
			it++;
		m_list.insert(it, pair.first);
	}

	// printList("m_list sorted:\t");
}


// HELPER FUNCTIONS

bool strIsDigit(std::string str) {
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void printIntPairVector(std::vector<std::pair<int, int>> vector) {
	for (size_t i = 0; i < vector.size(); i++) {
		if (i != 0)
			std::cout << " ";
		std::cout << "(" << vector[i].first << ", " << vector[i].second << ")";

	}
	std::cout << "\n";
}

void printIntPairList(std::list<std::pair<int, int>> list) {
	for (size_t i = 0; i < list.size(); i++) {
		if (i != 0)
			std::cout << " ";
		std::cout << "(" << std::next(list.begin(), i)->first << ", " << std::next(list.begin(), i)->second << ")";

	}
	std::cout << "\n";
}

// EXCEPTIONS

const char* PmergeMe::ArgumentException::what() const throw() {
	return "Error";
}