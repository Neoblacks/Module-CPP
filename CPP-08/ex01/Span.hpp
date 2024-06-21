/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:43:21 by amugnier          #+#    #+#             */
/*   Updated: 2024/03/11 16:16:52 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <exception>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &copy);
		Span &operator=(const Span &rhs);

		void addNumber(int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		const std::vector<int>* getVec() const;
		~Span();

	private:
		unsigned int _number;
		std::vector<int> _vec;
};

std::ostream &operator<<(std::ostream &o, const Span &rhs);

#endif
