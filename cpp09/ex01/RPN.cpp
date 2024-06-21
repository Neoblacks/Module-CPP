/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:01:59 by amugnier          #+#    #+#             */
/*   Updated: 2024/04/04 17:45:00 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}
RPN::RPN(char *string_input)
{
	int	first, second, result;
	int	digit = 0;
	int	sign = 0;

	for (int i = 0; string_input[i] != '\0'; i++)
	{
		if (string_input[i] == ' ')
			i++;
		if (isdigit(string_input[i]))
			digit++;
		if (string_input[i] == '+' || string_input[i] == '-' || string_input[i] == '*' || string_input[i] == '/')
			sign++;
	}
	if (sign != digit - 1)
	{
		std::cout << "Error: invalid expression" << std::endl;
		return;
	}

	for (int i = 0; string_input[i]; i++)
	{
		if (string_input[i] == ' ')
			i++;
		if (isdigit(string_input[i]))
		{
			std::cout << "push " << string_input[i] << std::endl;
			this->_stack.push(string_input[i] - '0');
		}
		else if ((string_input[i] == '+' || string_input[i] == '-' || string_input[i] == '*' || string_input[i] == '/') && this->_stack.size() >= 2)
		{
			second = this->_stack.top();
			this->_stack.pop();
			first = this->_stack.top();
			this->_stack.pop();
			if (string_input[i] == '+')
			{
				result = first + second;
				std::cout << "add " << first << " + " << second << " = " << result << std::endl;
			}
			else if (string_input[i] == '-')
			{
				result = first - second;
				std::cout << "sub " << first << " - " << second << " = " << result << std::endl;
			}
			else if (string_input[i] == '*')
			{
				result = first * second;
				std::cout << "mul " << first << " * " << second << " = " << result << std::endl;
			}
			else if (string_input[i] == '/')
			{
				if (second == 0)
				{
					std::cout << "Error: Explosion because of division by zero" << std::endl;
					return;
				}
				result = first / second;
				std::cout << "div " << first << " / " << second << " = " << result << std::endl;
			}
			std::cout << "push " << result << std::endl;
			this->_stack.push(result);

		}
		else
		{
			std::cout << "Error: invalid expression" << std::endl;
			return;
		}
	}
	std::cout << "Result: " << this->_stack.top() << std::endl;
	return;
}

RPN::RPN(const RPN &copy)
{
	this->_stack = copy._stack;
	*this = copy;
}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
		this->_stack = rhs._stack;
	return *this;
}

RPN::~RPN()
{
}
