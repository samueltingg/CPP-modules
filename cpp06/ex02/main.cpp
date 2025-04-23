/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:55:13 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 19:44:01 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <typeinfo>
#include <iostream>
#include <ctime>
#include <cstdlib>

// It randomly instanciates A, B or C and returns the instance as a Base pointer.
Base * generate(void)
{
	Base *ptr;

	std::srand(std::time(0));

	int choice = std::rand() % 3;
	// choice will only be 0, 1 or 2
	
	if (choice == 0)
		ptr = new A();
	else if (choice == 1)
		ptr = new B();
	else // choice == 2
		ptr = new C();
	
	return ptr;
}

//  prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p)
{
	const std::type_info& ti = typeid(*p);
	std::cout << "identify: type = \"" <<  ti.name() << "\"\n";
}

// prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer inside this function is forbidden.
void identify(Base& p)
{
	const std::type_info& ti = typeid(p);
	std::cout << "identify: type = \"" <<  ti.name() << "\"\n";

}

int main(void)
{
	{
		Base *p = generate();

		identify(p);
		delete p;
	}
	{
		B a;
		Base& r = a;

		identify(r);
	}

}
