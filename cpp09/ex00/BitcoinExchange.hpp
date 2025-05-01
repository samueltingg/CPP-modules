/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:40:46 by sting             #+#    #+#             */
/*   Updated: 2025/04/30 18:21:06 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>

class BitcoinExchange {
public:
	// Default Constructor
	BitcoinExchange();
	// Overloaded Constructor
	BitcoinExchange(std::string fileName);
	// Copy Constructor
	BitcoinExchange(const BitcoinExchange& other);
	// Copy Assignment Operator
	BitcoinExchange& operator=(const BitcoinExchange& other);
	// Destructor
	~BitcoinExchange();

	
	class ErrorOpeningFileException : std::exception {
	public: 
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw();
	};

private:
	std::map<std::string, int> _database;
};

#endif

