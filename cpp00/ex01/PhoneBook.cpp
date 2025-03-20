/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:53:05 by sting             #+#    #+#             */
/*   Updated: 2025/03/12 16:03:31 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void PhoneBook::addContact(Contact contact) {
	if (initialisedCount != 8)
		initialisedCount++;
	if (curContactCount == 8) {
		this->contacts[0] = contact;
		return ;
	}
	this->contacts[curContactCount] = contact;
	curContactCount++;
}

std::string truncateName(std::string name) {
	std::string truncatedName;

	if (name.length() > 10) {
		truncatedName = name.substr(0,9) + '.';
		return (truncatedName);
	}
	return (name);	
}

void PhoneBook::displaySavedContacts() {
    std::cout << std::right << std::setw(10) << "Index" 
			  << "|" << std::setw(10) << "First Name" 
			  << "|" << std::setw(10) << "Last Name" 
			  << "|" << std::setw(10) << "Nickname" << std::endl;
 
	for (int i = 0; i < initialisedCount; i++) {
		std::string str;
	    std::cout << std::right << std::setw(10) << i 
			  << "|" << std::setw(10) << truncateName(contacts[i].getFirstName())
			  << "|" << std::setw(10) << truncateName(contacts[i].getLastName())
			  << "|" << std::setw(10) << truncateName(contacts[i].getNickname()) << std::endl;
	}

}

void PhoneBook::displayContactByIndex(int i) {
	// include check if index is out of range?
	if (i + 1 > initialisedCount) {
		std::cout << "index does not exist." << std::endl;
		return ;
	}
	std::cout << "Index: "<< i << std::endl;
	std::cout << "First Name: "<< contacts[i].getFirstName() << std::endl;
	std::cout << "Last Name: "<< contacts[i].getLastName() << std::endl;
	std::cout << "Nickame: "<< contacts[i].getNickname() << std::endl;
	std::cout << "Phone Number: "<< contacts[i].getPhoneNum() << std::endl;
	std::cout << "Darkest Secret: "<< contacts[i].getDarkestSecret() << std::endl;
}

