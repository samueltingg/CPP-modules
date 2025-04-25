/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:19:49 by sting             #+#    #+#             */
/*   Updated: 2025/04/25 17:55:59 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// `typename` keyword is used to indicate that T::const_iterator is a type.
template <typename T>
typename T::const_iteractor easyfind(const T& container, int num)
{
	typename T::const_iterator it;

	for (it = container.begin(); it != container.end(); ++it) {
		if (container[it] == num)
			return it;
	}
}
