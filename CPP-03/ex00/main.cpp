/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:38:45 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/23 16:36:36 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int	main(void)
{
	ClapTrap claptrap1;
	ClapTrap claptrap2("Antoine");
	ClapTrap claptrap3(claptrap2);
	ClapTrap claptrap4("Edouard");

	std::cout << std::endl << std::endl;

	claptrap1.attack("Antoine");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(5);

	std::cout << std::endl << std::endl;

	claptrap3.attack("Edouard");
	claptrap4.takeDamage(10000);
	claptrap4.beRepaired(5);

	std::cout << std::endl << std::endl;

	claptrap2.attack("Edouard");
	claptrap3.takeDamage(9);
	claptrap3.beRepaired(10);

	std::cout << std::endl << std::endl;

	return (0);
}
