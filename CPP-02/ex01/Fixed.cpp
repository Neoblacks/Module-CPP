/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:26:02 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/09 15:12:31 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int nb_i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = nb_i << this->_frac_bits; //Bitwise left shift
}

Fixed::Fixed(const float nb_f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = roundf(nb_f * (1 << this->_frac_bits)); //Bitwise left shift
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixed_point = src.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_fixed_point;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}

int	Fixed::toInt(void) const
{
	return (this->_fixed_point >> this->_frac_bits); //Bitwise right shift
}

float	Fixed::toFloat(void) const
{
	return ((float) this->_fixed_point / (1 << this->_frac_bits));
}

std::ostream &operator<<(std::ostream &o, Fixed const &src)
{
	o << src.toFloat();
	return o;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
