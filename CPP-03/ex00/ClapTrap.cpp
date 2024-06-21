/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:39:17 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/23 16:35:11 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;

	_name = "default";
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;

	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;

	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;

	if (this != &src)
	{
		_name = src._name;
		_hit_points = src._hit_points;
		_energy_points = src._energy_points;
		_attack_damage = src._attack_damage;
	}
	return (*this);
}


void	ClapTrap::attack(std::string const & target)
{
	if ( _hit_points <= 0 || _energy_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack because he is dead or out of energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	_energy_points--;
}


void ClapTrap::takeDamage(unsigned int amount)
{
	if ((unsigned int)_hit_points <= amount)
	{
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " has no more hit points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ( _hit_points <= 0 || _energy_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired because he is dead or out of energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;
	_hit_points += amount;
	_energy_points--;
}


ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}


