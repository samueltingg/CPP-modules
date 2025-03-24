

#include <iostream>
#include "Harl.hpp"
/*
When creating apointer to a member function, must specify class name 
as pointer type includes class name
*/
void	Harl::complain( std::string level ) {
	const t_commentType arr[] = {
		{"DEBUG", &Harl::debug}, 
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
	};

	int arrSize = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < arrSize; i++) {
		if (arr[i].type == level) {
			arr[i].comment(); // need to dereference since it's a function ptr? 
			return ;
		}
	} 
}


void	debug( void ) {
	std::cout << "[DEBUG]" << std::endl;
}

void	info( void ) {
	std::cout << "[INFO]" << std::endl;
}

void	warning( void ) {
	std::cout << "[WARNING]" << std::endl;
}

void	error( void ) {
	std::cout << "[ERROR]" << std::endl;
}
