/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:55:10 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/31 13:25:44 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	// this->_weapon = NULL; // je verrais avec ceux qui ont fait le projet et correction
	std::cout << this->_name << " Born" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << this->_name << " is died" << std::endl;
}

void	HumanB::attack( void )
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with his hand " << std::endl;

}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
