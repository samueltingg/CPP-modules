/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:05:03 by sting             #+#    #+#             */
/*   Updated: 2025/05/06 11:34:57 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void printSection(const std::string &title) {
	std::cout << CYAN << BOLD << "\n=== " << title << " ===" << RESET
		<< std::endl;
}

long	getCurrentTime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec); // convert time into microseconds
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error: Expected more than 1 argument.\n";
		return (1);
	}
	
	std::vector<int> vector;
	try {
		argvToContainer(argv, vector);
		checkDuplicates(vector);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}

	if (isSorted(vector)) {
		std::cerr << "Sequence is already sorted.\n";
		return (0);
	}

	std::list<int> list;
	try {
		argvToContainer(argv, list);
		checkDuplicates(list);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}

	PmergeMe pm;
	
	// vector
	std::cout << GREEN << "Before:  " << RESET; 
	printContainer(vector);
	long start = getCurrentTime();
	pm.sortSequence(vector);
	long end = getCurrentTime();
	std::cout << RED << "After:  " << RESET; 
	double duration1 = end - start;
	printContainer(vector);
	std::cout << "Time to process a range of " << vector.size() 
			  << " elements with std::vector : " 
			  << std::fixed << std::setprecision(5)
			  << duration1 << " us\n";
	if (isSorted(vector))
		std::cout << "Sorted\n";
	else 
		std::cout << "Not Sorted\n";
	std::cout << "Expected No. of comparisons: " << F(vector.size()) << '\n';
	std::cout << "No. of comparisons: " << pm.getComparisonsCount() << '\n';

	//list 
	std::cout << GREEN << "Before:  " << RESET; 
	printContainer(list);
	start = getCurrentTime();
	pm.sortSequence(list);
	end = getCurrentTime();
	std::cout << RED << "After:  " << RESET; 
	printContainer(list);

	double duration2 = end - start;
	std::cout << "Time to process a range of " << list.size() 
			  << " elements with std::list : "
			  << std::fixed << std::setprecision(5)
			  << duration2 << " us\n";

	if (isSorted(list))
		std::cout << "Sorted\n";
	else 
		std::cout << "Not Sorted\n";
	std::cout << "Expected No. of comparisons: " << F(list.size()) << '\n';
	std::cout << "No. of comparisons: " << pm.getComparisonsCount() << '\n';
	
	// TEST comparison Count
	// pm.sortSequence(vector);
	// std::cout << "Sorted: ";
	// printContainer(vector);
	// std::cout << "Comparisons: " << PmergeMe::comparisonsCount << '\n';

	// TEST sort
	// pm.sortSequence(list);
	// if (isSorted(list))
	// 	std::cout << "Sorted\n";
	// else 
	// 	std::cout << "Not Sorted\n";


}

