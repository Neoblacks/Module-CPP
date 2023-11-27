/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:45:24 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/27 17:04:27 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string type);
		virtual ~AAnimal();

		AAnimal(const AAnimal &src);
		AAnimal &operator=(const AAnimal &src);
		std::string getType() const;

		virtual void makeSound() const;


	protected:
		std::string _type;
};

#endif
