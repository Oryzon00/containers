#include "type_traits.hpp"
#include <iostream>

int main(void)
{
	std::cout << "NO REMOVE CV" << std::endl;
	std::cout << "cons_bool: " << (ft::is_integral_base<const bool>::value)	<< std::endl;
	std::cout << "bool: " << (ft::is_integral_base<bool>::value)			<< std::endl;

	std::cout << std::endl << "-----------------" << std::endl << std::endl;

	std::cout << "YES REMOVE CV" << std::endl;
	std::cout << "cons_bool: " << (ft::is_integral<const bool>::value)	<< std::endl;
	std::cout << "bool: " << (ft::is_integral<bool>::value)			<< std::endl;

	std::cout << std::endl << "-----------------" << std::endl << std::endl;

	std::cout << "SWAP" << std::endl;
	int a = 1;
	int b = 2;
	std::cout << "a = " << a << " /// b = " << b << std::endl;
	ft::swap(a, b);
	std::cout << "a = " << a << " /// b = " << b << std::endl;

	std::cout << std::endl << "-----------------" << std::endl << std::endl;

}
