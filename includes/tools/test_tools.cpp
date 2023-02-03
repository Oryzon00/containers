#include "type_traits.hpp"
#include "pair.hpp"
#include <iostream>

#include <utility>

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


	std::cout << "PAIR" << std::endl;

	ft::pair<std::string, int>	p1("hola", -1);
	ft::pair<std::string, unsigned int> p2(p1);
	std::cout << "p1.second : " << p1.second << std::endl;
	std::cout << "p2.second : " << p2.second << std::endl;
	std::cout << std::endl;

	ft::pair <int, int> foo;
	foo = ft::make_pair(1, 42);
	std::cout << "make_pair : ";
	std:: cout << "first : " << foo.first <<  " //// second : " << foo.second << std::endl;
	std::cout << std::endl;

	ft::pair<int, int> bar = ft::make_pair(2, 42);
	bool output = foo < bar;
	std::cout << "comparaison: foo < bar = " << output << std::endl;
	std::cout << std::endl << "-----------------" << std::endl << std::endl;
	
	
}
