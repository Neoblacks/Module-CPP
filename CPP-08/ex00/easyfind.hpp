/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:50:10 by amugnier          #+#    #+#             */
/*   Updated: 2024/03/04 17:31:01 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# pragma once
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>


template<typename T>


typename T::const_iterator easyfind(T& container, int value)
{
	typename T::const_iterator it;

	// it = std::find(container.begin(), container.end(), value);
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	return (it);
}

#endif


// typename T::const_iterator easyfind(T& container, int value)
// {
// 	typename T::const_iterator it;


// 	it = std::find(container.begin(), container.end(), value);
// 	std::cout << "Value found at position : " << *it << std::endl;
// 	return (it);
// }
