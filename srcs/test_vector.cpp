
#include <iostream>
#include "../includes/vector.hpp"

int	main(void)
{
	ft::vector<int>	tab1(10);
	std::cout << "check" << std::endl;
	ft::vector<int>	tab2(10, 42);

	for (ft::vector<int>::iterator it = tab2.begin(); it != tab2.end(); it++)
		std::cout << *it << std::endl;


	return 0;
}
