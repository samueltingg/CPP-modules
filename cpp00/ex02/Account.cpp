/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:57:35 by sting             #+#    #+#             */
/*   Updated: 2025/03/14 14:26:43 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

static void	_displayTimestamp( void ) {
    // Get the current time
    std::time_t now = std::time(0); // Get current time as time_t
    std::tm *now_tm = std::localtime(&now); // Convert `time_t` value to `tm` structure

    char buffer[20]; // Buffer to hold the formatted string

    // Format the `tm` structure into desired format
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", now_tm);
	std::cout << buffer << std::endl;
}

Account::Account( int initial_deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" 
			  << _amount << ";created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" 
			  << _amount << ";closed" << std::endl;
}

static void	displayAccountsInfos( void ) {

}

static int	getNbAccounts( void );
static int	getTotalAmount( void );
static int	getNbDeposits( void );
static int	getNbWithdrawals( void );

void	makeDeposit( int deposit );
bool	makeWithdrawal( int withdrawal );
int		checkAmount( void ) const;
void	displayStatus( void ) const;


