/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:45:32 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/27 14:00:44 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << this->_type << " Constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << this->_type << " Are an animal which called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal makeSound called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}

Animal::~Animal()
{
	std::cout << this->_type << " Destructor called" << std::endl;
}
