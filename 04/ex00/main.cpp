/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:10:33 by likong            #+#    #+#             */
/*   Updated: 2024/10/08 16:06:40 by likong           ###   ########.fr       */
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
	i = nullptr;
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
	WrongAnimal wrongOther;
	WrongCat wrongCat;
	
	wrongOther.makeSound(); 
	wrongCat.makeSound();
}

int	main(void){
	std::cout << "\n-----------From subject------------\n\n";
	forSubject();

	std::cout << "\n-----------From normal animal------------\n\n";
	forAnimal();

	std::cout << "\n-----------From normal animal------------\n\n";
	forWrongAnimal();
	
	return 0;
}
