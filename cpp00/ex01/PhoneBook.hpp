/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:53:09 by sting             #+#    #+#             */
/*   Updated: 2025/03/12 14:56:40 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook() : curContactCount(0), initialisedCount(0) {}
	void addContact(Contact contact);
	void displaySavedContacts();
	void displayContactByIndex(int index);

private:
	Contact contacts[8];
	static const int maxContactCount = 8; // a 'static' member variable shared among all instances of a class. Non-static member variables cannot be initialised directly in class definition
	int curContactCount; 
	int initialisedCount;
	
};


#endif
