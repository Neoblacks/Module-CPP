/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:02:02 by amugnier          #+#    #+#             */
/*   Updated: 2024/03/15 14:18:02 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cctype>
# include <cstdlib>

class RPN
{
	public:
		RPN();
		RPN(char *string_input);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &rhs);
		~RPN();

	private:
		std::stack<int> _stack;
};

#endif
