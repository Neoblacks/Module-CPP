/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:13:50 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/27 17:02:12 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): AAnimal("Dog")
{
	std::cout << this->_type << " constructor called" << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch (std::bad_alloc &error) {
		std::cout << error.what() << " Malloc failed" << std::endl;
	}
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}

Dog::Dog(const Dog &src)
{
	// std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}
