/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:58:31 by sting             #+#    #+#             */
/*   Updated: 2025/03/12 14:43:53 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"
#include "Contact.hpp"

/*
reason for 'const': 
if u pass in a temporary string(eg."First Name: ") to this function, 
a non-const param might be dangerous if function code tries to change it's value.
Temp strings/object don't have persistent location in memory.
*/
std::string getInputString(const std::string& prompt) {
	std::string input;
	
	while (1) {
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			if (std::cin.eof()) // exit if user types 'ctrl + D'
				std::exit(0);
		if (!input.empty())
			break ;
		std::cout << "Input cannot be empty. Please try again." << std::endl;
	}
	return (input);	
}

bool isNumber(const std::string& str)
{
	for (int i = 0; str[i]; i++) {
		if (!std::isdigit(str[i])) {
			std::cout << "Input must be a number." << std::endl;
			return (false);
		}
	}	
	return (true);
}

std::string getNumber(const std::string& prompt) {
	std::string input;

	while (1) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (!input.empty()) {
			if (!isNumber(input))
				continue ;
			break ;
		}
		std::cout << "Input cannot be empty. Please try again." << std::endl;
	}
	return (input);
}

int stringToInt(const std::string& str) {
    int result = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

int getIndex(const std::string& prompt) {
	std::string input;
	int index;

	while (true) {
		input = getNumber(prompt);
		if (input.length() > 1) { // prevent overflow
			std::cout << "Iindex must be within range of 0-7" << std::endl;
			continue ;  
		}
		index = stringToInt(input);
		if (index < 0 || index > 7) {
			std::cout << "Index must be within range of 0-7" << std::endl;
			continue ;  
		}
		break ;
	}
	return (index);	
}

int main() {
	PhoneBook phoneBook;

	std::string command;

	while (true) {
		command = getInputString("Enter a command (ADD, SEARCH or EXIT): ");
		if (command == "ADD") {
			Contact contact;
			contact.setFirstName(getInputString("First Name: "));	
			contact.setLastName(getInputString("Last Name: "));	
			contact.setNickname(getInputString("Nickname: "));	
			contact.setPhoneNum(getNumber("Phone Num: "));	
			contact.setDarkestSecret(getInputString("Darkest Secret: "));	
			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH"){ 
			phoneBook.displaySavedContacts();

			int index;
			index = getIndex("Enter the index you wish to search for: ");
			phoneBook.displayContactByIndex(index);
		}
		else if (command == "EXIT") {
			return 0;
		}
	}
	return (0);
}
