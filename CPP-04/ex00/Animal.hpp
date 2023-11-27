/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:45:24 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/27 13:56:09 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();

		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		std::string getType() const;

		virtual void makeSound() const;


	protected:
		std::string _type;
};

#endif
