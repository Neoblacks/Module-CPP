/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:21:10 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/23 16:48:17 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_energy_points = src._energy_points;
		this->_hit_points = src._hit_points;
		this->_attack_damage = src._attack_damage;
	}
	return (*this);
}

void	ScavTrap::guardGate()
{
	if (_hit_points <= 0 || _energy_points <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't be Gate keeper" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (_hit_points <= 0 || _energy_points <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack because he is dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	_energy_points -= 1;
}


ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
