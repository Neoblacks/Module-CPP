/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:09:06 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/24 17:01:24 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
public:
	Zombie(void);
	~Zombie(void);
	void	announce(void);
	void	set_name(std::string name);

private:
	std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);
