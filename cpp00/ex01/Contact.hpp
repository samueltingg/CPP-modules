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
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNum() const;
	std::string getDarkestSecret() const;

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string nickname);
	void setPhoneNum(std::string phoneNum);
	void setDarkestSecret(std::string darkestSecret);

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNum;
	std::string darkestSecret;
};


#endif
