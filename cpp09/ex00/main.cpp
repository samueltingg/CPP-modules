/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:05:03 by sting             #+#    #+#             */
/*   Updated: 2025/04/25 20:51:26 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(void)
{
	{
		try {
			BitcoinExchange bc("data.csv");
			std::cout << "printing database: \n";
			std::cout << bc << '\n' << "testt\n";
		}
		catch (BitcoinExchange::ErrorOpeningFileException& e) {
			std::cout << e.what() << '\n';
		}



	}		

}
