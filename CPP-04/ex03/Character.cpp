/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:35:45 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/27 18:34:39 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
	int	i = 0;
	std::cout << this->_name << " Born ";
	while (i < 4)
	{
		this->_inventory[i] = NULL;
		i++;
	}
	std::cout << "with " << i << " empty slots" << std::endl;
}

Character::Character(Character const &src)
{
	*this = src;
	std::cout << this->_name << " Born by copy" << std::endl;
}

Character &Character::operator=(Character const &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = src._inventory[i];
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << this->_name << " equiped with " << m->getType() << "in slot :" << i << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (this->_inventory[idx])
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
		std::cout << this->_name << " unequiped" << std::endl;
	}
	else
		std::cout << this->_name << " inventory is empty or can't unequiped" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (this->_inventory[idx])
	{
		std::cout << this->_name << " used " << this->_inventory[idx]->getType() << std::endl;
		this->_inventory[idx]->use(target);
	}
	else
		std::cout << this->_name << " inventory is empty or can't use" << std::endl;
}

Character::~Character()
{
	std::cout << this->_name << " died" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}
