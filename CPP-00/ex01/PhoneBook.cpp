/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:09:25 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/19 14:33:51 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
}

PhoneBook::~PhoneBook( void )
{
}

void	PhoneBook::add_new_contact(void)
{
	static int i;
	this->_contact[i % 8].initialization();
	this->_contact[i % 8].set_index(i % 8);
	i++;
}

int	PhoneBook::_readcin(void) const
{
	int		i;
	bool	is_valid = false;
	while (!is_valid)
	{
		std::cout << "Please choice a Contact with his index" << std::endl;
		std::cout << "> " << std::flush;
		std::cin >> i;
		if (std::cin.good() && i >= 0 && i < 9)
			is_valid = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid input" << std::endl;
		}
	}
	return (i);
}

void	PhoneBook::search_contact(void) const
{
	int	i = this->_readcin();
	this->_contact[i].display_contact_info(i);
}

void	PhoneBook::display_contact(void) const
{
	int i = -1;
	while (i++ < 7) // maybe change to 8 and -1 to 0
		this->_contact[i].viewing(i);
}

void	PhoneBook::enter_phonebook(void) const
{
	std::cout << "HELLO ! I'M YOUR PHONEBOOK !" << std::endl;
	std::cout << "What do you want to do ?" << std::endl;
	std::cout << "ADD a new contact ?" << std::endl;
	std::cout << "SEARCH a contact ?" << std::endl;
	std::cout << "DISPLAY all contacts ?" << std::endl;
	std::cout << "EXIT ?" << std::endl;
}


