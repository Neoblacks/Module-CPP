/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:27:58 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/01 16:41:29 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Constructor Harl called" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Destructor Harl called" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string choiceStr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string	choiceInt[4] = {"1", "2", "3", "4"};


	void (Harl::*p[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i ++)
	{
		if (level == choiceStr[i] || level == choiceInt[i])
		{
			(this->*p[i])();
			return ;
		}
	}
	std::cerr << "Guys really we have only 4 levels of Harl come on !" << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}
