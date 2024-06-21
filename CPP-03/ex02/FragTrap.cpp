/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:19 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/23 16:50:07 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) // Call ClapTrap base constructor with src as parameter to copy all attributes
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src; //This ensures that FragTrap class members are copied correctly.
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hit_points = src._hit_points;
		this->_attack_damage = src._attack_damage;
		this->_energy_points = src._energy_points;
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (_hit_points <= 0 || _energy_points <= 0)
	{
		std::cout << "FragTrap " << this->_name << " can't give an high fives because he is dead or has no energy" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " give an high fives to you" << std::endl;
}

void FragTrap::attack(std::string const &target)
{
	if (_energy_points <= 0 || _hit_points <= 0)
	{
		std::cout << "FragTrap " << this->_name << " can't attack because he is dead or has no energy" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attack " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}
