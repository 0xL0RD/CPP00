/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:46:13 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/11 17:44:05 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " "
		<< "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::_displayTimestamp(void)
{
	char timestr[100];
	std::time_t	time = std::time(NULL);

	std::strftime(timestr, sizeof(timestr), "[%Y%m%d_%H%M%S]",
			std::localtime(&time));
	std::cout << timestr;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " "
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount - withdrawal < 0)
	{
		_displayTimestamp();
		std::cout << " "
			<< "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";";
		std::cout << "withdrawal:refused";
		std::cout << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << " "
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount + withdrawal << ";";
	std::cout << "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " "
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return ;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	/*
	if (initial_deposit > 0)
		this->_nbDeposits = 1;
		*/
	_displayTimestamp();
	std::cout << " "
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << initial_deposit << ";"
		<< "created";
	std::cout << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " "
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed";
	std::cout << std::endl;
}
