/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:41:37 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/25 15:14:47 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->setType(type);
	std::cout << "Create " << this->getType() << std::endl;
}

Weapon::~Weapon( void )
{
	std::cout << "Broken " << this->getType() << std::endl;
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}

std::string Weapon::getType( void )
{
	return (_type);
}


