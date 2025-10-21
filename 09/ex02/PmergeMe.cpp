/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:53:50 by likong            #+#    #+#             */
/*   Updated: 2025/10/21 11:53:52 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool strIsDigit(std::string str);

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
	sortVector(m_vec);
	auto stopTime = std::chrono::high_resolution_clock::now();
	m_vecSortTime = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

	startTime = std::chrono::high_resolution_clock::now();
	sortList(m_list);
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

// Binary insertion
template <typename Seq>
void binaryInsertion(Seq& a, const int value) {
    #ifdef DEBUG
    std::cout << "  [binaryInsertion] Insert " << value << " into ";
    #endif
    std::size_t left = 0, right = a.size();
    while (left < right) {
        std::size_t mid = left + (right - left) / 2;
        #ifdef DEBUG
        std::cout << "    compare " << value << " with a[" << mid << "]=" << a[mid] << '\n';
        #endif
        if (value < a[mid])
            right = mid;
        else
            left  = mid + 1;
    }
    #ifdef DEBUG
    std::cout << "    => position = " << left << "\n";
    #endif
    a.insert(a.begin() + static_cast<std::ptrdiff_t>(left), value);

    #ifdef DEBUG
    std::cout << "    result: ";
    for (int v : a) std::cout << v << ' ';
    std::cout << "\n\n";
    #endif
}

/* Jacobsthal and insertion order
   Generates a strictly increasing Jacobsthal sequence >= 1 (excluding 0) until >= limit
   J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
   For the convenience of recursion, keep the internal state of J0=0, J1=1 */
std::vector<std::size_t> generateJacobsthalNumbers(std::size_t limit) {
    #ifdef DEBUG
    std::cout << "[generateJacobsthalNumbers] limit = " << limit << '\n';
    #endif
    std::vector<std::size_t> j = {1};
    std::size_t j0 = 0, j1 = 1;
    while (true) {
        std::size_t jn = j1 + 2 * j0;
        if (jn >= limit || jn == j.back()) break;
        j.push_back(jn);
        j0 = j1;
        j1 = jn;
    }

    #ifdef DEBUG
    std::cout << "  Jacobsthal sequence: ";
    for (auto v : j) std::cout << v << ' ';
    std::cout << "\n\n";
    #endif
    
    return j;
}

// Return the subscripts of B in the order of
// Jacobsthal first, then fill in the remaining unused subscripts
std::vector<std::size_t> generateOptimalInsertOrder(std::size_t bSize) {
    #ifdef DEBUG
    std::cout << "[generateOptimalInsertOrder] bSize = " << bSize << '\n';
    #endif
    std::vector<std::size_t> order;
    order.reserve(bSize);

    if (bSize == 0) return order;

    // First generate candidates according to Jacobsthal (limited to [0, bSize))
    const auto jac = generateJacobsthalNumbers(bSize);
    std::vector<bool> used(bSize, false);
    #ifdef DEBUG
    std::cout << "  Using Jacobsthal indices first:\n";
    #endif
    for (std::size_t v : jac) {
        if (v < bSize && !used[v]) {
            #ifdef DEBUG
            std::cout << "    -> take index " << v << '\n';
            #endif
            order.push_back(v);
            used[v] = true;
        }
    }

    #ifdef DEBUG
    std::cout << "  Filling remaining indices:\n";
    #endif
    // Fill in the remaining unused indexes in natural order
    for (std::size_t i = 0; i < bSize; ++i) {
        #ifdef DEBUG
        std::cout << "    -> take index " << i << '\n';
        #endif
        if (!used[i]) order.push_back(i);
    }

    #ifdef DEBUG
    std::cout << "  => final order: ";
    for (auto v : order) std::cout << v << ' ';
    std::cout << "\n\n";
    #endif
    
    return order;
}

// Ford–Johnson with Vector
void PmergeMe::sortVector(std::vector<int>& container) {
    const std::size_t size = container.size();
    if (size < 2) return;

    #ifdef DEBUG
    std::cout << "\n=== sortVector called with ";
    for (int v : container) std::cout << v << ' ';
    std::cout << "===\n";
    #endif

    // To form a pair, put the larger one first and the smaller one second
    std::vector<std::pair<int,int>> pairs;
    pairs.reserve(size / 2);
    for (std::size_t i = 0; i + 1 < size; i += 2) {
        int a = container[i];
        int b = container[i + 1];
        if (a < b) pairs.emplace_back(b, a);
        else       pairs.emplace_back(a, b);
    }

    #ifdef DEBUG
    std::cout << "  pairs: ";
    for (auto& p : pairs)
        std::cout << '(' << p.first << ',' << p.second << ") ";
    std::cout << '\n';
    #endif

    // Split into A (large element, which is the largest in each pair) and B (small element)
    std::vector<int> A; A.reserve((size + 1) / 2);
    std::vector<int> B; B.reserve(size / 2);
    for (const auto& p : pairs) {
        A.push_back(p.first);
        B.push_back(p.second);
    }
    // If it is an odd number, merge the last single element into A
    if (size % 2 == 1) A.push_back(container.back());

    #ifdef DEBUG
    std::cout << "  A (larger): ";
    for (int v : A) std::cout << v << ' ';
    std::cout << "\n  B (smaller): ";
    for (int v : B) std::cout << v << ' ';
    std::cout << "\n";
    #endif

    sortVector(A);

    // Insert the B elements back into A
    const std::vector<std::size_t> order = generateOptimalInsertOrder(B.size());
    #ifdef DEBUG
    std::cout << "  [Insertion phase]\n";
    #endif
    for (std::size_t idx : order) {
        if (idx < B.size())
            binaryInsertion(A, B[idx]);
    }

    #ifdef DEBUG
    std::cout << "  => Merged result: ";
    for (int v : A) std::cout << v << ' ';
    std::cout << "\n";
    #endif

    // cover back to original container
    container.swap(A);
}

// Ford–Johnson with List
void PmergeMe::sortList(std::list<int>& container) {
    const std::size_t size = container.size();
    if (size < 2) return;

    // Store in pairs (max,min)
    std::vector<std::pair<int,int>> pairs;
    pairs.reserve(size / 2);

    auto it = container.begin();
    while (it != container.end()) {
        int first = *it;
        auto it2 = std::next(it);
        if (it2 == container.end()) break;
        int second = *it2;
        if (first < second) pairs.emplace_back(second, first);
        else                pairs.emplace_back(first,  second);
        std::advance(it, 2);
    }

    // Split into A (list: the largest value within) and B (vector: the smallest value)
    std::list<int> A;
    std::vector<int> B;
    A.clear(); B.clear();
    A.resize(0); B.reserve(pairs.size());

    for (const auto& p : pairs) {
        A.push_back(p.first);
        B.push_back(p.second);
    }
    if (size % 2 == 1) A.push_back(container.back());

    sortList(A);

    // Jacobsthal order + binary position insertion
    const std::vector<std::size_t> order = generateOptimalInsertOrder(B.size());
    for (std::size_t idx : order) {
        if (idx < B.size()) {
            const int val = B[idx];
            // Find the first position in A (ascending order) that is >= val
            auto pos = std::lower_bound(A.begin(), A.end(), val);
            A.insert(pos, val);
        }
    }

    container.swap(A);
}

bool strIsDigit(std::string str) {
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

const char* PmergeMe::ArgumentException::what() const throw() {
	return "Error";
}
