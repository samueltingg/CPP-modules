/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:54:43 by sting             #+#    #+#             */
/*   Updated: 2025/03/24 15:54:45 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "replace.hpp"
 
/*
start -> 1st index of str to be replaced
end -> last index of str to be replaced
str -> str to replace with
*/
std::string replace_str(const std::string& oriStr, size_t start, size_t end, const std::string& str) {
	
    // Check if the indices are valid
    if (start > end || end >= oriStr.length()) {
		std::cout << "Invalid start or end indices." << std::endl;
		return (oriStr);
    }
	std::string	modifiedStr = oriStr.substr(0, start) + str + oriStr.substr(end + 1);
	return (modifiedStr);
}

/*
`npos` is constant that indicates `find()` not finding any matches (value = -1)
*/
void replaceAll(std::string& content, const std::string& s1, const std::string& s2) {
	
	size_t pos = 0;
	size_t s1_length = s1.length();

	if (s1_length == 0)
		return ;
	while ((pos = content.find(s1, pos)) != std::string::npos) {
		content = replace_str(content, pos, pos + s1.length() - 1, s2);
		pos += s2.length();
	}
}
