/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:54:35 by sting             #+#    #+#             */
/*   Updated: 2025/03/24 15:54:41 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

std::string replace_str(const std::string& oriStr, size_t start, size_t end, const std::string& str);
void replaceAll(std::string& content, const std::string& s1, const std::string& s2);

#endif
