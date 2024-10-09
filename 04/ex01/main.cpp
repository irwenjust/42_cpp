/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:10:33 by likong            #+#    #+#             */
/*   Updated: 2024/10/08 16:04:30 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	forSubject(){
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete	j;
	j = nullptr;
	delete	i;
	i = nullptr;
}

void	forAnimal(){
	const Animal *animal[4];

	for (int i = 0; i < 4; i++){
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	for (int i = 0; i < 4; i++)
		animal[i]->makeSound();
	
	for (int i = 0; i < 4; i++){
		delete animal[i];
		animal[i] = nullptr;
	}
	
	std::cout << "\n-----------From deep copy------------\n\n";
	
	Cat cat;
	Cat copyCat(cat);
	Cat opeCopyCat = cat;
	
	cat.makeSound();
	copyCat.makeSound();
	opeCopyCat.makeSound();
}

int	main(void){
	std::cout << "\n-----------From subject------------\n\n";
	forSubject();

	std::cout << "\n-----------From animal------------\n\n";
	forAnimal();
	
	return 0;
}
