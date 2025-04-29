/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:06:11 by sting             #+#    #+#             */
/*   Updated: 2025/04/29 10:06:46 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

template <typename T>
MutantStack<T>::MutantStack() 
	: std::stack<T>()
{
	std::cout << GREY << "MutantStack:: Default Constructor Called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
	: std::stack<T>()  
{
	std::cout << GREY << "MutantStack:: Copy Constructor Called" << RESET << std::endl;

	std::stack<T> temp = other;

	while (!temp.empty()) {
		this->push(temp.top());
		temp.pop();
	}
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	std::cout << GREY << "MutantStack:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;

	// Clear current stack	
	while (!this->empty())
		this->pop();

	std::stack<T> temp = other;
	while (!temp.empty()) {
		this->push(temp.top());
		temp.pop();
	}

	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << GREY << "MutantStack:: Destructor Called" << RESET << std::endl;
}


#endif
