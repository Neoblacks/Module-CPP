/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:38:45 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/23 16:51:39 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap claptrap1;
	ClapTrap claptrap2("Claptrap2");
	ClapTrap claptrap3(claptrap2);

	std::cout << std::endl << std::endl;


	claptrap1.attack("Claptrap2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(5);
	claptrap3.attack("Claptrap1");
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(5);

	std::cout << std::endl << std::endl;

	ScavTrap scavtrap1("Scavtrap1");
	ScavTrap scavtrap2(scavtrap1);
	ScavTrap scavtrap3 = scavtrap1;

	std::cout << std::endl << std::endl;

	scavtrap1.attack("Scavtrap2");
	scavtrap2.takeDamage(200);
	scavtrap2.beRepaired(10);
	scavtrap2.guardGate();

	std::cout << std::endl << std::endl;

	scavtrap1.attack("Scavtrap3");
	scavtrap3.takeDamage(80);
	scavtrap3.beRepaired(2);
	scavtrap3.guardGate();

	std::cout << std::endl << std::endl;

	FragTrap fragtrap("MadMax");
	fragtrap.attack("Piou piou");
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(10);
	fragtrap.highFivesGuys();

	std::cout << std::endl << std::endl;

	return (0);

}
