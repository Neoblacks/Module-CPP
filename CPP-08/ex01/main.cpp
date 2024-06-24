/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:41:51 by amugnier          #+#    #+#             */
/*   Updated: 2024/06/24 12:00:08 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "\033[32m----------TEST 1-----------\033[0m" << std::endl << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(0);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(42);
	std::cout << "Vector elements: \033[32m" << std::endl << std::endl << sp << "\033[0m" << std::endl;
	std::cout << "ShortestSpan : " << sp.shortestSpan() << std::endl;
	std::cout << "LongestSpan : " << sp.longestSpan() << std::endl << std::endl;
	std:: cout << std::endl;
	std::cout << "\033[34m----------TEST 2-----------\033[0m" << std::endl << std::endl;
	try{
		std::vector<int> vec(10000);
		std::srand(time(0));
		std::generate(vec.begin(), vec.end(), std::rand);
		Span span = Span(vec.size());
		span.addNumber(vec.begin(), vec.end());
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[35m----------TEST 3-----------\033[0m" << std::endl << std::endl;
	try{
		Span span = Span(4);
		span.addNumber(1);
		std::cout << "Vector elements: \033[35m" << std::endl << std::endl << span << "\033[0m" << std::endl;
		span.addNumber(2);
		std::cout << "Vector elements: \033[35m" << std::endl << std::endl << span << "\033[0m" << std::endl;
		span.addNumber(3);
		std::cout << "Vector elements: \033[35m" << std::endl << std::endl << span << "\033[0m" << std::endl;
		span.addNumber(4);
		std::cout << "Vector elements: \033[35m" << std::endl << std::endl << span << "\033[0m" << std::endl;
		span.addNumber(5);
		std::cout << "Vector elements: \033[35m" << std::endl << std::endl << span << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
