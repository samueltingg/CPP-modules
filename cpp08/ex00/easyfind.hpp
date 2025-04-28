/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:19:49 by sting             #+#    #+#             */
/*   Updated: 2025/04/28 09:11:43 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

// `typename` keyword is used to indicate that T::const_iterator is a type.
template <typename T>
typename T::const_iterator easyfind(const T& container, int num)
{
	typename T::const_iterator it; 
	// 'const_iterator' -> element pointed by it can't be modified

	for (it = container.begin(); it != container.end(); ++it) {
		if (*it == num)
			return it;
	}
	return container.end();
}

#endif
