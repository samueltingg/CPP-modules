/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:11:28 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 19:32:49 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
#define A_HPP

#include "Base.hpp"
#include <iostream>

class A : public Base {
public:
	virtual ~A(){
		std::cout << "A: Destructor called\n";
	};
};

#endif
