/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:01:14 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/27 17:02:12 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();


	delete j;
	delete i;
	Dog basic;
	{
		Dog tmp = basic;
	}

	const AAnimal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}
