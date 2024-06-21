/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:41:37 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/22 13:47:49 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	setType(type);
	std::cout << "Constructor called" << std::endl;
}

const std::string Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(std::string newType)
{
	this->_type = newType;
}

Weapon::~Weapon()
{
	std::cout << "Destructor called" << std::endl;
}


