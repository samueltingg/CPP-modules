/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkOverflow.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:05:36 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 18:05:50 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Returns Overflow type
e_OverflowType checkOverflow(const std::string literal, e_LiteralType type)
{
	if (!(type == INT || type == FLOAT || type == DOUBLE))
		return NO_OVERFLOW;

	double num = strtod(literal.c_str(), NULL);
	if (num == -HUGE_VAL || num == HUGE_VAL)
		return D_OVERFLOW;
	else if (isFloatExeceedingLimits(num))
		return F_OVERFLOW;
	else if (isIntExeceedingLimits(num))
		return I_OVERFLOW;
	else if (isCharExeceedingLimits(num))
		return C_OVERFLOW;
	else 
		return NO_OVERFLOW;
}
