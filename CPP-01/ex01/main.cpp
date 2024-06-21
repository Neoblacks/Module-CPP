/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:02:34 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/22 14:33:59 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *Zombie = zombieHorde(30, "Zombie");

	for (int i = 0; i < 30; i++)
		Zombie[i].announce();
	delete [] Zombie;
	return (0);
}
