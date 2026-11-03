/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:03:13 by nippolit          #+#    #+#             */
/*   Updated: 2025/07/24 20:03:32 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// contructeur default
Account::Account(void) :
	_amount(0),
	_accountIndex(Account::_nbAccounts++),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}

// contructeur
Account::Account(int initial_deposit) :
	_amount(initial_deposit),
	_accountIndex(Account::_nbAccounts++),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}

// destructeur
Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
}


//fonction-----------------------------------------------------------

void
Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

void
Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount + deposit << ";"
		<< "nb_deposits:" << this->_nbDeposits
		<< std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool
Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";";
	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->_amount - withdrawal << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return true;
}

int
Account::checkAmount(void) const
{
	return (this->_amount);
}

void
Account::_displayTimestamp(void)
{
	const time_t t = std::time(0);
	tm *time = std::localtime(&t);

	std::cout
		<< std::setfill('0') << std::right
		<< "["
		<< time->tm_year + 1900
		<< std::setw(2) << time->tm_mon + 1
		<< std::setw(2) << time->tm_mday
		<< "_"
		<< std::setw(2) << time->tm_hour
		<< std::setw(2) << time->tm_min
		<< std::setw(2) << time->tm_sec
		<< "]";
}

//static------------------------------------------------------------

void
Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout
		<< " accounts:" << Account::_nbAccounts << ";"
		<< "total:" << Account::_totalAmount << ";"
		<< "deposits:" << Account::_totalNbDeposits << ";"
		<< "withdrawals:" << Account::_totalNbWithdrawals
		<< std::endl;
}

int
Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int
Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int
Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int
Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}
