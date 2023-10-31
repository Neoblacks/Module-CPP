/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:54:49 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/31 13:10:20 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->_name = name;
	this->_weapon = &weapon;
	std::cout << this->_name << " born " <<std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " is dead" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
