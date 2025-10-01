#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "\n---Constructor---\n\n";
	try{
		Form testA;
		std::cout << testA << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	try{
		Form testB("testB", 1, 150);
		std::cout << testB << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try{
		Form testC("testC", 150, 1);
		std::cout << testC << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\n---TooHigh grade---\n\n";
	try{
		Form testHighA("testHighA", 0, 42);
		std::cout << testHighA << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		Form testHighB("testHighB", 42, -3);
		std::cout << testHighB << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---TooLow grade---\n\n";
	try{
		Form testLowA("testLowA", 151, 42);
		std::cout << testLowA << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	try{
		Form testLowB("testLowB", 42, 200);
		std::cout << testLowB << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---Sign Test---\n\n";
	Form formTest("FormTest", 50, 42);
	std::cout << formTest << std::endl;
	Bureaucrat	A("A", 49);
	Bureaucrat	B("B", 51);
	Bureaucrat	C("C", 50);

	A.signForm(formTest);
	std::cout << std::endl;
	B.signForm(formTest);
	B.incrementGrade();
	B.signForm(formTest);
	std::cout << std::endl;
	C.decrementGrade();
	C.signForm(formTest);

	return 0;
}