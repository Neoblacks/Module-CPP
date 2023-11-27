/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:01:14 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/27 15:48:05 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << std::endl << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << std::endl << std::endl;

	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl << std::endl;
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl << std::endl;

	const WrongAnimal *wrong_animal = new WrongAnimal();
	const WrongAnimal *wrong_cat = new WrongCat();
	std::cout << std::endl << std::endl;

	std::cout << "Type of Wrong : " << wrong_animal->getType() << " " << std::endl;
	std::cout << "Type of Wrong animal : " << wrong_cat->getType() << " " << std::endl;

	std::cout << std::endl << std::endl;
	wrong_animal->makeSound();
	wrong_cat->makeSound();
	std::cout << std::endl << std::endl;
	delete wrong_animal;
	delete wrong_cat;

	return 0;
}
