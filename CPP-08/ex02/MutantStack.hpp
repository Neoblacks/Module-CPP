/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:58:30 by amugnier          #+#    #+#             */
/*   Updated: 2024/06/24 13:55:57 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stack>
# include <algorithm>
# include <deque>
# include <list>
# include <vector>

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

