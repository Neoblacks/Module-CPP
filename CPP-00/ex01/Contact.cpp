/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:28:45 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/19 14:12:19 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact()
{
}
Contact::~Contact(void)
{
}

std::string Contact::_get_contact(std::string str) const
{
	std::string input_contact = "";
	bool is_valid = false;
	while (!is_valid)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input_contact);
		if (std::cin.good() && !input_contact.empty())
			is_valid = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input" << std::endl;
		}
	}
	return (input_contact);
}

void	Contact::initialization(void)
{
	this->_first_name = this->_get_contact("First name: ");
	this->_last_name = this->_get_contact("Last name: ");
	this->_nickname = this->_get_contact("Nickname: ");
	this->_phone_number = this->_get_contact("Phone number: ");
	this->_darkest_secret = this->_get_contact("Darkest secret: ");
	std::cout << "Contact added" << std::endl;
}

std::string Contact::_printlen(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::viewing(int index) const
{
	if (this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty())
	{
		std::cout << "Contact " << index << " is empty" << std::endl;
		return;
	}
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->_printlen(this->_first_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->_printlen(this->_last_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->_printlen(this->_nickname) << std::flush;
	std::cout << std::endl;
}

void	Contact::set_index(int i)
{
	this->_index = i;
}

void	Contact::display_contact_info(int index) const
{
	if (this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty())
		return ;
	std::cout << std::endl << "Contact " << index << std::endl;
	std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << std::endl;
}
