/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:41:37 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/31 13:05:43 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Create " << this->getType() << std::endl;
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
	std::cout << this->getType() << " Destroyed" << std::endl;
}


