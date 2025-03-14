/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:52:59 by sting             #+#    #+#             */
/*   Updated: 2025/03/12 13:48:59 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
	void setFirstName(std::string firstName);
	std::string getFirstName();
	void setLastName(std::string lastName);
	std::string getLastName();
	void setNickname(std::string nickname);
	std::string getNickname();
	void setPhoneNum(std::string phoneNum);
	std::string getPhoneNum();
	void setDarkestSecret(std::string darkestSecret);
	std::string getDarkestSecret();

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNum;
	std::string darkestSecret;
};


#endif
