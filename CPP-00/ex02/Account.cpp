/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:01:55 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/24 17:59:46 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit )
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
	_nbAccounts--;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << std::flush;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" <<_nbDeposits << std::endl;
}


bool Account::makeWithdrawal( int withdrawal )
{
	int	check = checkAmount();
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << std::flush;
	if (withdrawal <= check)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << withdrawal << "->refused" << std::endl;
		return (false);
	}
}

int Account::checkAmount( void ) const
{
	return (_amount);
}

void Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals <<std::endl;
}

void Account::_displayTimestamp( void )
{
	std::time_t timestamp= std::time(0);
	char	buffer[20];
	//this line will display the timestamp in the following format: [20231020_133712]
	struct tm *tm_info = std::localtime(&timestamp);
	strftime(buffer, sizeof(buffer),"%Y%m%d_%H%M%S", tm_info);
	std::cout << "[" << buffer << "] ";
}
