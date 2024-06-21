/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:58:30 by amugnier          #+#    #+#             */
/*   Updated: 2024/03/12 14:16:22 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stack>
# include <deque>
# include <list>
# include <algorithm>

template < typename T, class Container = std::deque<T> >

class MutantStack : public std::stack  < T, Container >
{
	public:
		MutantStack() {};
		MutantStack(MutantStack const &rhs) { *this = rhs; }
		MutantStack &operator=(MutantStack const &rhs) {
			std::stack < T, Container >::operator=(rhs);
			return *this;
		}
		typedef typename Container::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		~MutantStack() {};
};

