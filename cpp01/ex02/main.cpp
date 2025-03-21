/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:20:42 by sting             #+#    #+#             */
/*   Updated: 2025/03/21 09:31:48 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main( void ) {

	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "memory address of `str`: " << &str << std::endl; 
	std::cout << "memory address of `stringPTR`: " << &stringPTR << std::endl; 
	std::cout << "memory address of `stringREF`: " << &stringREF << std::endl; 
	// a Reference has the same memory address to the variable it is referencing to
	
	std::cout << std::endl;
	std::cout << "value of str: " << str << std::endl;	
	std::cout << "value pointed ot by `stringPTR`: " << *stringPTR << std::endl;	
	std::cout << "value pointed ot by `stringREF`: " << stringREF << std::endl;	 
}
