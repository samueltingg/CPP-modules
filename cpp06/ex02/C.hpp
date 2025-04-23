/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:12:48 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 19:33:01 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
#define C_HPP

#include "Base.hpp"
#include <iostream>

class C : public Base {
public:
	virtual ~C(){
		std::cout << "C: Destructor called\n";
	};
};

#endif
