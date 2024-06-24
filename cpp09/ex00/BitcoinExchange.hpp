/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:35 by amugnier          #+#    #+#             */
/*   Updated: 2024/06/24 15:43:27 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cctype>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		void	Input(const std::string &filename);
		~BitcoinExchange();
		double	getRate(const std::string &date) { return _Rate(date); }
		void	setData(const std::string &date, double value) { _data[date] = value; }

	private:
		std::map<std::string, double> _data;
		double	_Rate(const std::string &date);
		bool	_CheckValue(double &value);
		bool	_CheckDate(std::string &date);
};


#endif
