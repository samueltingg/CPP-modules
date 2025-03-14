/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:52:17 by sting             #+#    #+#             */
/*   Updated: 2025/03/12 13:55:32 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"


void Contact::setFirstName(std::string firstName) {
	this->firstName = firstName; // using 'this' as param and class variable have same name
}

std::string Contact::getFirstName() {
	return (firstName);
}

void Contact::setLastName(std::string lastName) {
	this->lastName = lastName; 
}

std::string Contact::getLastName() {
	return (lastName);
}

void Contact::setNickname(std::string nickname) {
	this->nickname = nickname; 
}

std::string Contact::getNickname() {
	return (nickname);
}

void Contact::setPhoneNum(std::string phoneNum) {
	this->phoneNum = phoneNum; 
}

std::string Contact::getPhoneNum() {
	return (phoneNum);
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->darkestSecret = darkestSecret; 
}

std::string Contact::getDarkestSecret() {
	return (darkestSecret);
}










