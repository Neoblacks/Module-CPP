// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/04 16:13:34 by amugnier          #+#    #+#             */
// /*   Updated: 2024/03/04 17:43:22 by amugnier         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	int tab[] = {1, 2, 3, 4, 10, 6, 7, 8, 9, 11};
	std::cout << "-- Test with a vector and value inside --" << std::endl;
	std::vector<int> vec(tab, tab + 10);
	std::vector<int>::const_iterator it;
	try
	{
		it = easyfind(vec, 10);
		std::cout << "Value : " << *it << " Found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}
	std::cout << "-- Test with a vector and value not inside --" << std::endl;
	try
	{
		it = easyfind(vec, 42);
		std::cout << "Value : " << *it << " Found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}
	std::cout << "-- Test with a list and value inside --" << std::endl;
	std::list<int> lst(tab, tab + 10);
	std::list<int>::const_iterator it2;
	try
	{
		it2 = easyfind(lst, 1);
		std::cout << "Value : " << *it2 << " Found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}
	std::cout << "-- Test with a list and value not inside --" << std::endl;
	try
	{
		it2 = easyfind(lst, 42);
		std::cout << "Value : " << *it2 << " Found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}
	return (0);
}
