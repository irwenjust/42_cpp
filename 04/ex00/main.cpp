/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:10:33 by likong            #+#    #+#             */
/*   Updated: 2024/10/09 17:41:03 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	forSubject(){
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete	meta;
	meta = nullptr;
	delete	j;
	j = nullptr;
	delete	i;
	i = nullptr;
}

void	forAnimal(){
	Animal other;
	Dog dog;
	Cat cat;
	Cat catCopy(cat);
	
	other.makeSound(); 
	dog.makeSound();
	cat.makeSound();
	catCopy.makeSound();
}

void	forWrongAnimal(){
	WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal	*wrongCat = new WrongCat();
	
	std::cout << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();

	delete	wrongAnimal;
	wrongAnimal = nullptr;
	delete	wrongCat;
	wrongCat = nullptr;
}

int	main(void){
	std::cout << "\n-----------From subject------------\n\n";
	forSubject();

	std::cout << "\n-----------From normal animal------------\n\n";
	forAnimal();

	std::cout << "\n-----------From Wrong animal------------\n\n";
	forWrongAnimal();
	
	return 0;
}
