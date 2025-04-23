/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:54:35 by sting             #+#    #+#             */
/*   Updated: 2025/04/23 17:29:59 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREY "\033[90m"

void printSection(const std::string &title) {
	std::cout << CYAN << BOLD << "\n=== " << title << " ===" << RESET
		<< std::endl;
}

int main(void)
{
	printSection("Subject PDF test");
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	


	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	printSection("Testing min/max with same values");
	int x = 2;
	int y = 2;
	
	std::cout << "address of y(2nd value): " << &y << "\n";

	std::cout << "x = " << x << ", y = " << y << std::endl;

	std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
	std::cout << "address of min's return value: " << &(::min( x, y )) << "\n";

	std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;
	std::cout << "address of max's return value: " << &(::max( x, y )) << "\n";

	return 0;
}
