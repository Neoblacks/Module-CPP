/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:09:06 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/24 16:50:10 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
public:
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);

private:
	std::string _name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
