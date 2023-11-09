/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:26:05 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/09 15:38:28 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int nb_i);
		Fixed(const float nb_f);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator==(const Fixed &src) const;
		bool	operator!=(const Fixed &src) const;
		bool	operator>(const Fixed &src) const;
		bool	operator<(const Fixed &src) const;
		bool	operator>=(const Fixed &src) const;
		bool	operator<=(const Fixed &src) const;

		Fixed	operator+(const Fixed &src) const;
		Fixed	operator-(const Fixed &src) const;
		Fixed	operator*(const Fixed &src) const;
		Fixed	operator/(const Fixed &src) const;

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);

		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);


	private:
		int _fixed_point;
		static const int _frac_bits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &src);

