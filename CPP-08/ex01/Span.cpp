/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:43:15 by amugnier          #+#    #+#             */
/*   Updated: 2024/06/24 11:59:02 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n)
{
	_number = n;
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
		this->_number = rhs._number;
	return *this;
}

void Span::addNumber(int n)
{
	if (_vec.size() < _number)
		_vec.push_back(n);
	else
		throw std::out_of_range("Vector is full");

}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vec.size() + std::distance(begin, end) <= _number)
		_vec.insert(_vec.end(), begin, end);
	else
		throw std::out_of_range("Vector is full");
}

unsigned int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw std::out_of_range("Not enough elements in vector");
	unsigned int min = Span::longestSpan();
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		std::vector<int>::iterator it2 = it;
		it2++;
		while (it2 != _vec.end())
		{
			int diff = std::abs(*it - *it2);
			unsigned int diff2 = diff;
			if (diff2 < min)
				min = std::abs(*it - *it2);
			it2++;
		}
	}
	return min;
}

unsigned int Span::longestSpan()
{
	if (_vec.size() < 2)
		throw std::out_of_range("Not enough elements in vector");
	return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}

const std::vector<int>* Span::getVec() const
{
	return &_vec;
}

std::ostream &operator<<(std::ostream &o, const Span &rhs)
{
	for (std::vector<int>::const_iterator it = rhs.getVec()->begin(); it != rhs.getVec()->end(); it++)
	{
		o << *it << std::endl<< "---" << std::endl;
	}
	return o;
}

Span::~Span()
{
}
