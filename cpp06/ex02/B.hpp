/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:12:20 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 19:32:44 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
#define B_HPP

#include "Base.hpp"
#include <iostream>

class B : public Base {
public:
	virtual ~B(){
		std::cout << "B: Destructor called\n";
	};
};

#endif
