/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileio.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:54:49 by sting             #+#    #+#             */
/*   Updated: 2025/03/24 15:54:51 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEIO_HPP
#define FILEIO_HPP

#include <string>

std::string readFile(const std::string& fileName);
void writeFile(const std::string& fileName, const std::string& content);

#endif 
