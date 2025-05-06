/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:44:26 by sting             #+#    #+#             */
/*   Updated: 2025/05/05 11:20:30 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREY "\033[90m"

#include <deque>
#include <stack>
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <cmath>

enum tokenType {
	PLUS,
	MINUS,
	TIMES,
	DIVIDE,
	NUM
};

class RPN {
public:
	// Overloaded Constructor
	RPN(std::string expression);
	// Copy Constructor
	RPN(const RPN& other);
	// Copy Assignment Operator
	RPN& operator=(const RPN& other);
	// Destructor
	~RPN();

	// Member Functions:
	void printTokens(std::ostream& os);
	int calcExpression();

	// Exceptions:
	class InvalidTokenException : std::exception {
	public: 
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw();
	};

private:
	std::deque<std::string> _tokens;
	// Default Constructor
	RPN();
};


#endif

