/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:39 by amugnier          #+#    #+#             */
/*   Updated: 2024/06/24 17:23:15 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: file csv not found" << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::string::size_type pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: invalid file csv format" << std::endl;
			return ;
		}
		std::string date = line.substr(0, pos);
		std::string value_rate = line.substr(pos + 1);

		//Check if value rate is only digit or '.'
		if (value_rate.find_first_not_of("0123456789.") != std::string::npos)
		{
			std::cerr << "Error: invalid file csv format " << value_rate << std::endl;
			return ;
		}
		if(_CheckDate(date) == false)
		{
			std::cerr << "Error: invalid date csv format " << date << std::endl;
			continue ;
		}
		std::istringstream iss(value_rate);
		double value;
		if (!(iss >> value))
		{
			std::cerr << "Error: invalid file csv format " << value_rate << std::endl;
			return ;
		}
		_data[date] = value;
	}
	file.close();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	_data = rhs._data;
	return *this;
}

void	BitcoinExchange::Input(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: file not txt found" << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string::size_type pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: No delimeter ('|') in this line " << line << std::endl;
			continue ;
		}
		std::string string_value = line.substr(pos + 2);
		if (string_value.find_first_not_of("0123456789.") != std::string::npos)
		{
			std::cerr << "Error: Number must be a digit" << std::endl;
			continue ;
		}
		double value;
		char del;
		if (!(iss >> date >> del >> value))
		{
			std::cerr << "Error: invalid file txt format " << line << std::endl;
			continue ;
		}
		if (!_CheckDate(date))
		{
			std::cerr << "Error: invalid date format " << date << std::endl;
			continue ;
		}
		if (!_CheckValue(value))
			continue ;
		double rate = _Rate(date);
		if (rate == -1.0)
		{
			std::cerr << "Error: no rate found for " << date << " in csv file" << std::endl;
			continue ;
		}
		std::cout << "\033[1;32m" <<  date << " => " << value << " => " << value * rate << "\033[0m" << std::endl;
	}
}

bool BitcoinExchange::_CheckValue(double &value)
{
	if (value < 0 || value > 1000)
	{
		std::cout << "Error: Number out of range ( 0 < value < 1000 )" << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::_CheckDate(std::string &date)
{
	if (date.size() != 10)
		return false;
	std::string::size_type i = date.find('-');
	std::string::size_type j = date.rfind('-');

	if (i == std::string::npos || j == i)
		return false;

	std::string year_s = date.substr(0, i);
	std::string month_s = date.substr(i + 1, j - i - 1);
	std::string day_s = date.substr(j + 1);

	if (year_s.size() != 4 || month_s.size() != 2 || day_s.size() != 2)
		return false;

	std::istringstream iss(year_s), iss2(month_s), iss3(day_s);
	int year, month, day;
	if (!(iss >> year) || !(iss2 >> month) || !(iss3 >> day))
		return false;

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	else if (month == 2)
	{
		bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (leap && day > 29)
			return false;
		else if (!leap && day > 28)
			return false;
	}
	else if (day > 31)
		return false;
	return true;
}



double BitcoinExchange::_Rate(const std::string &date)
{
	std::map<std::string, double>::iterator it = _data.upper_bound(date);
	if (it->first != date && it != _data.begin())
		--it;
	if (it != _data.end())
	{
		if (date < it->first)
		{
			return -1.0;
		}
		return it->second;
	}
	else if (!(_data.empty()))
		return it->second;
	return -1.0;
}


BitcoinExchange::~BitcoinExchange()
{
}
