/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:28:45 by amugnier          #+#    #+#             */
/*   Updated: 2023/09/23 17:18:55 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact( float const f ) : pi(f), qd(42)
{
	std::cout << "Contact constructor called" << std::endl;
	return ;
}


void Contact::function2(void) const
{
	std::cout << "this->qd = " << this->qd << std::endl;
	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "Function called" << std::endl;
	return;
}
Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return ;
}
