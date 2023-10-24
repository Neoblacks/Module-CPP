/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:08:45 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/24 16:52:10 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie ZombieStack("ZombieStack");
	ZombieStack.announce();

	Zombie *ZombieHeap = newZombie("ZombieHeap");
	ZombieHeap->announce();
	delete ZombieHeap;

	randomChump("randomChump");
}
