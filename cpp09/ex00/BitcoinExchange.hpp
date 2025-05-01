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

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREY "\033[90m"


#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>

class BitcoinExchange {
public:
	// Overloaded Constructor
	BitcoinExchange(std::string fileName);
	// Copy Constructor
	BitcoinExchange(const BitcoinExchange& other);
	// Copy Assignment Operator
	BitcoinExchange& operator=(const BitcoinExchange& other);
	// Destructor
	~BitcoinExchange();
	
	typedef std::map<std::string, double>::iterator iterator;
	typedef std::map<std::string, double>::const_iterator const_iterator;
	typedef std::map<std::string, double>::reverse_iterator reverse_iterator;
	typedef std::map<std::string, double>::const_reverse_iterator const_reverse_iterator;
	
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();

	
	class ErrorOpeningFileException : std::exception {
	public: 
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw();
	};

private:
	std::map<std::string, double> _database;

	// Default Constructor
	BitcoinExchange();
};

std::ostream& operator<<(std::ostream& os, BitcoinExchange& bitcoinExchange);

#endif

