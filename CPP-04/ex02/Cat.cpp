/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:15:16 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/27 17:02:12 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat")
{
	std::cout << this->_type << " constructor called" << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch (std::bad_alloc &error) {
		std::cout << error.what() << " Malloc failed" << std::endl;
	}
}

void Cat::makeSound() const
{
	std::cout << "MEOW MEOW" << std::endl;
}

Cat::Cat(const Cat &src)
{
	// std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}
