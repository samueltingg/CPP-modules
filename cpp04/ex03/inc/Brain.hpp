/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:55:00 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 18:04:29 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:

	// Constructor
	Brain();
	// Copy Constructor
	Brain(const Brain& other);
	// Copy Assignment Operator
	Brain& operator=(const Brain& other);
	// Destructor
	~Brain();
	
	// Getter?
private:
	std::string ideas[100];
};

#endif
