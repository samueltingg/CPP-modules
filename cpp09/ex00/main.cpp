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

#include <vector>
#include <list>
#include "easyfind.hpp"
#include <iostream>
#include <deque>
#include <stack>

int main(void)
{
	{
		std::vector<int> vector;
		vector.push_back(1);	
		vector.push_back(2);	
		vector.push_back(3);	
		vector.push_back(4);	

		std::vector<int>::const_iterator it;

		it = easyfind(vector, 2);
		std::cout << *it << '\n';

		std::cout << "Test: finding num that doesn't exist in container\n";
		it = easyfind(vector, 5);
		if (it == vector.end())
			std::cout << "Num doesn't exist\n";
		else
			std::cout << "Num does exist\n";

	}

	{
		std::list<int> list;
		list.push_back(1);	
		list.push_back(2);	
		list.push_back(3);	
		list.push_back(4);	

		std::list<int>::const_iterator it;

		it = easyfind(list, 2);

		std::cout << *it << '\n';
	}
	{
		std::deque<int> deque;
		deque.push_back(1);	
		deque.push_back(2);	
		deque.push_back(3);	
		deque.push_back(4);	

		std::deque<int>::const_iterator it;

		it = easyfind(deque, 2);

		std::cout << *it << '\n';
	}

}
