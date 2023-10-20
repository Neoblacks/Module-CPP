/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:11:44 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/19 14:24:10 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook Phonebook;
	std::string input = "";
	Phonebook.enter_phonebook();
	while (input != "EXIT")
	{
		std::cout << "Enter your choice "<< std::endl;
		if (input == "ADD")
			Phonebook.add_new_contact();
		else if (input == "SEARCH")
		{
			Phonebook.display_contact();
			Phonebook.search_contact();
		}
		std::cout << "> " << std::flush;
		std::getline(std::cin, input);
		std::cout << input << std::endl;
	}

	return (0);
}
