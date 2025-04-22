/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:00:33 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 18:03:28 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

e_LiteralType	checkType(std::string literal)
{
	if (isPseudoFloatLiteral(literal)) {
		colorPrint("Type: PSEUDO_FLOAT\n");
		return PSEUDO_FLOAT;
	}
	else if (isPseudoDoubleLiteral(literal)) {
		colorPrint("Type: PSEUDO_DOUBLE\n");
		return PSEUDO_DOUBLE;
	}
	else if (isSinglePrintableChar(literal)) {
		colorPrint("Type: CHAR\n");
		return CHAR;
	}
	else if (isIntegerLiteral(literal)) {
		colorPrint("Type: INT\n");
		return INT;
	}
	else if (isFloatLiteral(literal)) {
		colorPrint("Type: FLOAT\n");
		return FLOAT;
	}
	else if (isDoubleLiteral(literal)) {
		colorPrint("Type: DOUBLE\n");
		return DOUBLE;
	}
	else {
		colorPrint("Type: INVALID\n");
		return INVALID;
	}
}
