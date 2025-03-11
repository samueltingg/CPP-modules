/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:58:31 by sting             #+#    #+#             */
/*   Updated: 2025/03/11 16:20:48 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook phonebook;
	Contact contact1;
	contact1.first_name = "john";
	phonebook.contacts[0] = contact1;

	std::cout << phonebook.contacts[0].first_name << std::endl;

}
