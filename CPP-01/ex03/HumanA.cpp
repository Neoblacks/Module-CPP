/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:54:49 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/22 13:47:29 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->_name = name;
	this->_weapon = &weapon;
}

HumanA::~HumanA()
{
}

void	HumanA::attack() const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
