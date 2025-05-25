/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeInsertionSort.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:10:38 by sting             #+#    #+#             */
/*   Updated: 2025/05/14 18:23:55 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int strToInt(const std::string& str)
{
	char *endPtr;
	long num = strtol(str.c_str(), &endPtr, 10);

	if (endPtr[0] != '\0')
		throw PmergeMe::InvalidArgumentException();
	if (num < 0 || num > INT_MAX || num == LONG_MAX)
		throw PmergeMe::NumberOutOfRangeException();
	return num;
}

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}
