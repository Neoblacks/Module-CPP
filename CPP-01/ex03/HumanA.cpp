/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:54:49 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/25 15:06:48 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon):_weapon(weapon)
{
	this->_name = name;
	std::cout << this->_name << " Take " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " is dead" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attack with their " << this->_weapon.getType() << "." << std::endl;
}
