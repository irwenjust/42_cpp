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
	Form formTest("FormTest", 24, 42);
	std::cout << formTest << std::endl;
	Bureaucrat	A("A", 20);
	Bureaucrat	B("B", 24);
	Bureaucrat	C("C", 25);
	Bureaucrat	D("D", 24);

	A.signForm(formTest);
	B.signForm(formTest);
	std::cout << std::endl;
	C.signForm(formTest);
	C.incrementGrade();
	C.signForm(formTest);
	std::cout << std::endl;
	D.decrementGrade();
	D.signForm(formTest);

	return 0;
}