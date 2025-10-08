#include <iostream>
#include "iter.hpp"

#define BLUE "\033[34m"
#define WHITE "\033[0m"

int main(void)
{
    std::cout << BLUE << "\n----------Test----------\n\n" << WHITE;
	
	std::cout << BLUE << "\n----------Int Array----------\n\n" << WHITE;
	int intArray[] = {123, -456, 7, 89, -10, 0};
    size_t intArrayLen = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Int array: ";
    iter(intArray, intArrayLen, [](int x){ std::cout << x << " "; });

    std::cout << "\nIncrement int array: ";
    iter(intArray, intArrayLen, [](int& x){ x += 1; });
    iter(intArray, intArrayLen, [](int x){ std::cout << x << " "; });
    std::cout << std::endl;

    std::cout << BLUE << "\n----------Float Array----------\n\n" << WHITE;
	float floatArray[] = {12.3f, -4.56f, 0.7f, 89.0f, -1.0f, 0.0f};
    size_t floatArrayLen = sizeof(floatArray) / sizeof(floatArray[0]);
    std::cout << "Float array: ";
    iter(floatArray, floatArrayLen, [](float x){ std::cout << x << " "; });

    std::cout << "\nFloat array multiply by two: ";
    iter(floatArray, floatArrayLen, [](float& x){ x *= 2.0f; });
    iter(floatArray, floatArrayLen, [](float x){ std::cout << x << " "; });
    std::cout << std::endl;

    std::cout << BLUE << "\n----------Double Array----------\n\n" << WHITE;
	double doubleArray[] = {12.3, -4.56, 0.7, 89.0, -1.0, 0.0};
    size_t doubleArrayLen = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Double array: ";
    iter(doubleArray, doubleArrayLen, [](double x){ std::cout << x << " "; });

    std::cout << "\nDouble array divided by two: ";
    iter(doubleArray, doubleArrayLen, [](double& x){ x /= 2.0; });
    iter(doubleArray, doubleArrayLen, [](double x){ std::cout << x << " "; });
    std::cout << std::endl;

    std::cout << BLUE << "\n----------Char Array----------\n\n" << WHITE;
	char charArray[] = {'c', 'C', '&', 'z', '+'};
    size_t charArrayLen = sizeof(charArray) / sizeof(charArray[0]);
    std::cout << "Char array: ";
    iter(charArray, charArrayLen, [](char x){ std::cout << x << " "; });

    std::cout << "\nChar array move forward: ";
    iter(charArray, charArrayLen, [](char& x){ x -= 1; });
    iter(charArray, charArrayLen, [](char x){ std::cout << x << " "; });
    std::cout << std::endl;

    std::cout << BLUE << "\n----------String Array----------\n\n" << WHITE;
	std::string stringArray[] = {"hi,", "thiS", "is The", "cPP-module-07."};
    size_t stringArrayLen = sizeof(stringArray) / sizeof(stringArray[0]);
    std::cout << "String array: ";
    iter(stringArray, stringArrayLen, [](std::string x){ std::cout << x << " "; });

    std::cout << "\nto uppercase: ";
    iter(stringArray, stringArrayLen, [](std::string& x){
        for (char& c : x) {
            c = std::toupper(static_cast<unsigned char>(c));
        }
    });
    iter(stringArray, stringArrayLen, [](std::string x){ std::cout << x << " "; });
    std::cout << std::endl;

    std::cout << BLUE << "\n----------Testing Done----------\n\n" << WHITE;
	return (0);
}
