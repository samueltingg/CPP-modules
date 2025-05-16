/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:23:27 by sting             #+#    #+#             */
/*   Updated: 2025/05/14 17:54:23 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define GREY "\033[90m"


#include <vector>
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <cmath>
#include <limits.h> 
#include <utility>

typedef std::vector< std::pair<int, int> > PairedSeq;
void printVector(std::vector<int>& vec);

typedef std::vector<int>::iterator Iterator;
void mergeInsertionSort(std::vector<int>& container, int pairLevel);

class PmergeMe {
public:
	// Overloaded Constructor
	// PmergeMe(std::string sequence);
	PmergeMe(char **sequence);
	// Copy Constructor
	PmergeMe(const PmergeMe& other);
	// Copy Assignment Operator
	PmergeMe& operator=(const PmergeMe& other);
	// Destructor
	~PmergeMe();

	// Member Functions:
	std::vector<int> sortSequence();
	void printOriSequence();

	// Exceptions:
	class InvalidArgumentException : public std::exception {
	public: 
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw();
	};

	class NumberOutOfRangeException : public std::exception {
	public: 
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw();
	};


private:
	std::vector<int> _sequence;
	// Default Constructor
	PmergeMe();
};

#endif

