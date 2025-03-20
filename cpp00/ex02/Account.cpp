/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:57:35 by sting             #+#    #+#             */
/*   Updated: 2025/03/17 11:23:27 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// Define and initialize static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0; 

void	Account::_displayTimestamp( void ) {
    // Get the current time
    std::time_t now = std::time(0); // Get current time as time_t
    std::tm *now_tm = std::localtime(&now); // Convert `time_t` value to `tm` structure

    char buffer[20]; // Buffer to hold the formatted string

    // Format the `tm` structure into desired format
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", now_tm);
	std::cout << buffer << " ";
}

Account::Account( int initial_deposit ) {
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	std::cout << "index:" << _accountIndex << ";amount:" 
			  << _amount << ";created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" 
			  << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) { // not in use 
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) { // not in use 
	return (_totalAmount);
}
int	Account::getNbDeposits( void ) { // not in use 
	return (_totalNbDeposits);  // _totalNbDeposits or _nbDeposits?
}

int	Account::getNbWithdrawals( void ) { // not in use 
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts 
			  << ";total:" << _totalAmount 
			  << ";deposits:" << _totalNbDeposits 
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit ) {
	int prev_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << prev_amount 
		      << ";deposit:" << deposit 
			  << ";amount:" << _amount 
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	int prev_amount = _amount;

	_displayTimestamp();
	if (withdrawal > _amount) {
		std::cout << "index:" << _accountIndex 
				  << ";p_amount:" << prev_amount 
				  << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << prev_amount 
		      << ";withdrawal:" << withdrawal 
			  << ";amount:" << _amount 
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);

}

int	Account::checkAmount( void ) const { // not in use
	return (0);
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount 
			  << ";deposits:" << _nbDeposits 
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}
