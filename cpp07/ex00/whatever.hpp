/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:54:46 by sting             #+#    #+#             */
/*   Updated: 2025/04/23 17:23:49 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b)
{
	T tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
const T&	min(const T& a, const T& b)
{
	return (b <= a) ? b : a;
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	return (b >= a) ? b : a;
}

#endif
