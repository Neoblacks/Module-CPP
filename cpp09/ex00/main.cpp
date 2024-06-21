/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:51:49 by amugnier          #+#    #+#             */
/*   Updated: 2024/03/14 13:28:41 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./bitcoin [filename]" << std::endl;
		return 1;
	}
	BitcoinExchange exchange("data.csv");
	exchange.Input(argv[1]);
	return 0;
}
