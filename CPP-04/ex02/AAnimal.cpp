/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:45:32 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/29 11:35:30 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << this->_type << " Constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << this->_type << " Are an AAnimal which called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal makeSound called" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->_type);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called" << std::endl;
}
