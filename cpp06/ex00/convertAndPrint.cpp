/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertAndPrint.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:59:36 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 18:11:00 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

void	convertAndPrint(const std::string literal, e_LiteralType type)
{
	int decPlacesCount = countDecimalPlaces(literal);
	if (decPlacesCount == 0)
		decPlacesCount = 1;
	e_OverflowType overflowType = checkOverflow(literal, type);

	if (type == PSEUDO_FLOAT)
		printPseudoFloat(literal);
	else if (type == PSEUDO_DOUBLE)
		printDoubleFloat(literal);
	else if (type == CHAR)
		printFromChar(literal, decPlacesCount);
	else if (type == INT)
		printFromInt(literal, overflowType, decPlacesCount);
	else if (type == FLOAT)
		printFromFloat(literal, overflowType, decPlacesCount);
	else if (type == DOUBLE)
		printFromDouble(literal, overflowType, decPlacesCount);
	else // NECESSARY?? std::cerr << "Invalid literal\n";
		return ;
}

