/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:32:02 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/27 18:26:52 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{

}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "This AMateria : " << this->_type << " Constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria* AMateria::clone() const
{
	return ((AMateria*)this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "This AMateria : " << this->_type << " is used on " << target.getName() << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "This AMateria : " << this->_type << " Destructor called" << std::endl;
}
