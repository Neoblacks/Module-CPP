/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:31:27 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/24 17:41:11 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main (void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << &str << ":" << str << std::endl;
	std::cout << stringPTR << ":" << *stringPTR << std::endl;
	std::cout << &stringREF << ":" << stringREF << std::endl;

	return (0);
}
