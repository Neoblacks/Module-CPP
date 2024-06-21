/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:40:49 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/29 11:37:36 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain born" << std::endl;
}

Brain::Brain(Brain const &src)
{
	// std::cout << "Brain copy born" << std::endl;
	*this = src;
}

Brain &Brain::operator=(Brain const &src)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain died" << std::endl;
}
