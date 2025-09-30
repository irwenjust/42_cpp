/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:53:37 by likong            #+#    #+#             */
/*   Updated: 2025/09/30 12:53:37 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	std::cout << "\n---Constructor---\n\n";
	try{
		Bureaucrat testA;
		std::cout << testA << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat testB("testB", 1);
		std::cout << testB << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat testC("testB", 100);
		std::cout << testC << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---TooHigh grade---\n\n";
	try{
		Bureaucrat testHighA("testHigh", 0);
		std::cout << testHighA << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat testHighB("testHigh", -1);
		std::cout << testHighB << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---TooLow grade---\n\n";
	try{
		Bureaucrat testLowA("testLow", 151);
		std::cout << testLowA << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat testLowB("testLow", 2147483647);
		std::cout << testLowB << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---Increment---\n\n";
	try{
		Bureaucrat testIn("testIn", 3);
		std::cout << testIn << std::endl;

		testIn.incrementGrade();
		std::cout << testIn << std::endl;

		testIn.incrementGrade();
		std::cout << testIn << std::endl;

		testIn.incrementGrade();
		std::cout << testIn << std::endl;
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---Decrement---\n\n";
	try{
		Bureaucrat testDe("testDe", 148);
		std::cout << testDe << std::endl;

		testDe.decrementGrade();
		std::cout << testDe << std::endl;

		testDe.decrementGrade();
		std::cout << testDe << std::endl;

		testDe.decrementGrade();
		std::cout << testDe << std::endl;

	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}