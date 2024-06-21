/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:49:09 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/29 12:54:51 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
}

MateriaSource &MateriaSource::operator=(MateriaSource const & src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
			_materia[i] = src._materia[i];
	}
	return (*this);
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return (_materia[i]->clone());
	}
	std::cout<< "This materia doesn't exist" << std::endl;
	return (NULL);
}

AMateria *MateriaSource::getMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return (_materia[i]);
	}
	return (NULL);
}

void MateriaSource::learnMateria(AMateria *material)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_materia[i])
		{
			_materia[i] = material;
			return ;
		}
	}
	delete material;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i])
			delete _materia[i];
	}
}
