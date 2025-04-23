/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:37:29 by sting             #+#    #+#             */
/*   Updated: 2025/04/23 18:01:41 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template < typename T >
void print( T const & x ) 
{ 
	std::cout << x << std::endl; 
	return; 
}

template <typename T>
void	iter(T *arr, int len, void (*func)(const T&))
{
	for (int i = 0; i < len; i++) {
		func(arr[i]);
	}
}

#endif
