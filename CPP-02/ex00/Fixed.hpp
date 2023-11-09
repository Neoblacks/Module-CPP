/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:26:05 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/09 14:54:31 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _fixed_point;
		static const int _frac_bits = 8;
};

