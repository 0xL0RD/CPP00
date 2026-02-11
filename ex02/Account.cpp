/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:46:13 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/11 15:54:56 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

static void	Account::_displayTimestamp(void);
{
	char timestr[100];
	std::time_t	time;

	time = std::time(nullptr);

	std::strftime(timestr, sizeof(timestr), "[yyyymmdd_hhmmss]",
			std::localtime(&time));
	std::cout << "[" << timestr << "]";
}

void	makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;
}

bool	makeWithdrawal(int withdrawal)
{
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

}

int		checkAmount(void) const
{
	return (this->_amount);
}

void	displayStatus(void) const
{
	return ;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	if (initial_deposit > 0)
		this->_nbDeposits = 1;
	_displayTimestamp();
	std::cout << " "
		<< index:0;"
		<< "amount:"
		<< initial_deposit
		<< ";"
		<< "created";
}
