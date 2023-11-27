/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:40:49 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/27 16:10:13 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain born" << std::endl;
}

Brain::Brain(Brain const &copy)
{
	// std::cout << "Brain copy born" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(Brain const &copy)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain died" << std::endl;
}
