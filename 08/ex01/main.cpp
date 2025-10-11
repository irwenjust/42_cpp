#include "Span.hpp"
#include <iostream>
#include <ctime>

int main(void) {
    std::cout << "\n----------Normal Test----------\n\n";
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n----------Add more numbers----------\n\n";
    try {
        sp.addNumber(23);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------span size == 0----------\n\n";
    try {
        Span spTest0 = Span(0);
        std::cout << spTest0.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------span size < 2----------\n\n";
    try {
        Span spTest1 = Span(1);
        spTest1.addNumber(1);
        std::cout << spTest1.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------span size >= 2 but only one number----------\n\n";
    try {
        Span spTest2 = Span(20);
        spTest2.addNumber(1);
        std::cout << spTest2.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------span size >= 2 && numbers.size >= 2----------\n\n";
    try {
        Span spTest3 = Span(25);
        spTest3.addNumber(1);
        spTest3.addNumber(-2);
        spTest3.addNumber(6);
        std::cout << spTest3.shortestSpan() << std::endl;
        std::cout << spTest3.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------negative span size----------\n\n";
    try {
        Span spTest4 = Span(-25);
        spTest4.addNumber(1);
        spTest4.addNumber(-2);
        spTest4.addNumber(11);
        spTest4.addNumber(-52);
        std::cout << spTest4.shortestSpan() << std::endl;
        std::cout << spTest4.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------max and min number----------\n\n";
    try {
        Span spTest5 = Span(5);
        spTest5.addNumber(0);
        spTest5.addNumber(-2147483648);
        spTest5.addNumber(10);
        spTest5.addNumber(2147483637);
        spTest5.addNumber(1);
        std::cout << spTest5.shortestSpan() << std::endl;
        std::cout << spTest5.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------same number----------\n\n";
    try {
        Span spTest6 = Span(3);
        spTest6.addNumber(7);
        spTest6.addNumber(7);
        spTest6.addNumber(7);
        std::cout << spTest6.shortestSpan() << std::endl;
        std::cout << spTest6.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------iterator test----------\n\n";
    try {
        Span spTest7 = Span(5);
        std::vector<int> numbers = {2, 4, -6, 8, 10};
        spTest7.addNumbers(numbers.begin(), numbers.end());
        std::cout << spTest7.shortestSpan() << std::endl;
        std::cout << spTest7.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------oversize iterator test----------\n\n";
    try {
        Span spTest8 = Span(5);
        std::vector<int> numbers = {2, 4, -6, 8, 10, 12};
        spTest8.addNumbers(numbers.begin(), numbers.end());
        std::cout << spTest8.shortestSpan() << std::endl;
        std::cout << spTest8.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------big span size----------\n\n";
    try {
        const unsigned int bigSize = 10001; 
        Span spTest9 = Span(bigSize);

        std::vector<int> bigNumbers(bigSize);
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        std::generate(bigNumbers.begin(), bigNumbers.end(), std::rand);

        spTest9.addNumbers(bigNumbers.begin(), bigNumbers.end());
        std::cout << spTest9.shortestSpan() << std::endl;
        std::cout << spTest9.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
	return (0);

}