#include "PmergeMe.hpp"

static bool strIsDigit(std::string str);
// static void printIntPairVector(std::vector<std::pair<int, int>> vector);
// static void printIntPairList(std::list<std::pair<int, int>> list);

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

/* =========================
   二分插入：通用模板
   ========================= */
template <typename Seq>
void binaryInsertion(Seq& a, const int value) {
    #ifdef DEBUG
    std::cout << "  [binaryInsertion] Insert " << value << " into ";
    #endif
    // 在已升序的 a 中找上界位置
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

/* =========================
   Jacobsthal 与插入顺序
   ========================= */

// 生成严格递增且 >=1 的 Jacobsthal 序列（不含 0），直到 >= limit
// J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)；插入次序通常从 1 开始使用
std::vector<std::size_t> generateJacobsthalNumbers(std::size_t limit) {
    #ifdef DEBUG
    std::cout << "[generateJacobsthalNumbers] limit = " << limit << '\n';
    #endif
    std::vector<std::size_t> j = {1}; // 从 1 开始
    // 为了递推方便，保留 J0=0, J1=1 的内部状态
    std::size_t j0 = 0, j1 = 1; // J(0), J(1)
    while (true) {
        std::size_t jn = j1 + 2 * j0;  // 下一项
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

// 把 B 的下标按“Jacobsthal 优先，然后补齐剩余未用下标”的顺序返回
std::vector<std::size_t> generateOptimalInsertOrder(std::size_t bSize) {
    #ifdef DEBUG
    std::cout << "[generateOptimalInsertOrder] bSize = " << bSize << '\n';
    #endif
    std::vector<std::size_t> order;
    order.reserve(bSize);

    if (bSize == 0) return order;

    // 先按 Jacobsthal 产生候选（限制在 [0, bSize) ）
    const auto jac = generateJacobsthalNumbers(bSize);
    std::vector<bool> used(bSize, false);
    #ifdef DEBUG
    std::cout << "  Using Jacobsthal indices first:\n";
    #endif
    for (std::size_t v : jac) {
        // 通常论文里用 1-based 的 J(k)；我们的 B 是 0-based。
        // 这里直接使用 0-based 的值，已经在生成时从 1 起步并裁剪 < bSize。
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
    // 再把剩余没用到的索引按自然序补齐
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



/* =========================
   核心递归：Ford–Johnson
   ========================= */
void PmergeMe::sortVector(std::vector<int>& container) {
    const std::size_t size = container.size();
    if (size < 2) return;

    #ifdef DEBUG
    std::cout << "\n=== sortVector called with ";
    for (int v : container) std::cout << v << ' ';
    std::cout << "===\n";
    #endif

    // 1) 组成配对，把较大者放 first，较小者放 second（便于后面逻辑）
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

    // 2) 拆成 A（大元素，已按“各对内最大”）与 B（小元素）
    std::vector<int> A; A.reserve((size + 1) / 2);
    std::vector<int> B; B.reserve(size / 2);
    for (const auto& p : pairs) {
        A.push_back(p.first);
        B.push_back(p.second);
    }
    // 若为奇数个，把最后落单的元素并入 A
    if (size % 2 == 1) A.push_back(container.back());

    #ifdef DEBUG
    std::cout << "  A (larger): ";
    for (int v : A) std::cout << v << ' ';
    std::cout << "\n  B (smaller): ";
    for (int v : B) std::cout << v << ' ';
    std::cout << "\n";
    #endif

    // 3) 递归排序 A（只对各对内的“大值”序列排序）
    sortVector(A);

    // 4) 按 Jacobsthal 最优插入次序，把 B 元素二分插回 A
    const std::vector<std::size_t> order = generateOptimalInsertOrder(B.size());
    #ifdef DEBUG
    std::cout << "  [Insertion phase]\n";
    #endif
    for (std::size_t idx : order) {
        if (idx < B.size())
            binaryInsertion(A, B[idx]); // 二分寻找位置再插入
    }

    #ifdef DEBUG
    std::cout << "  => Merged result: ";
    for (int v : A) std::cout << v << ' ';
    std::cout << "\n";
    #endif

    // 5) 覆盖回原容器
    container.swap(A);
}



/* =========================
   核心递归：Ford–Johnson（list）
   ========================= */
void PmergeMe::sortList(std::list<int>& container) {
    const std::size_t size = container.size();
    if (size < 2) return;

    // 1) 两两成对，按 (max,min) 存
    std::vector<std::pair<int,int>> pairs;
    pairs.reserve(size / 2);

    auto it = container.begin();
    while (it != container.end()) {
        int first = *it;
        auto it2 = std::next(it);
        if (it2 == container.end()) break; // 落单的留到后面处理
        int second = *it2;
        if (first < second) pairs.emplace_back(second, first);
        else                pairs.emplace_back(first,  second);
        std::advance(it, 2);
    }

    // 2) 拆成 A（list：对内较大值）与 B（vector：较小值）
    std::list<int> A;
    std::vector<int> B;
    A.clear(); B.clear();
    A.resize(0); B.reserve(pairs.size());

    for (const auto& p : pairs) {
        A.push_back(p.first);
        B.push_back(p.second);
    }
    // 若为奇数个，把最后落单的元素并入 A
    if (size % 2 == 1) A.push_back(container.back());

    // 3) 递归排序 A
    sortList(A);

    // 4) Jacobsthal 次序 + 二分定位插回（对 list 用 ranges::lower_bound）
    const std::vector<std::size_t> order = generateOptimalInsertOrder(B.size());
    for (std::size_t idx : order) {
        if (idx < B.size()) {
            const int val = B[idx];
            // 在 A（升序）中找第一个 >= val 的位置
            auto pos = std::lower_bound(A.begin(), A.end(), val);
            A.insert(pos, val);
        }
    }

    // 5) 覆盖回原容器
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