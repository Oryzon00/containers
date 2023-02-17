
#include <iostream>
#include <string>
#include "../includes/vector.hpp"

int	main(void)
{
	
	
	
	

	/* DEFAULT CONSTRUCTOR */
	ft::vector<int>	tab1(5);

	std::cout << "DEFAULT CONSTRUCTOR" << std::endl;
	for (ft::vector<int>::iterator it = tab1.begin(); it != tab1.end(); it++)
		std::cout << *it << std::endl;
	
	std::cout << "-------------------------------------------" << std::endl;

	/* FILL CONSTRUCTOR INTEGRAL */
	ft::vector<int>	tab2(5, 42);

	std::cout << "FILL CONSTRUCTOR INTEGRAL" << std::endl;
	for (ft::vector<int>::iterator it = tab2.begin(); it != tab2.end(); it++)
		std::cout << *it << std::endl;
	
	std::cout << "-------------------------------------------" << std::endl;

	/* FILL CONSTRUCTOR COMPLEX */
	ft::vector<std::string>	tab3(5, "hola");

	std::cout << "DEFAULT CONSTRUCTOR COMPLEX" << std::endl;
	for (ft::vector<std::string>::iterator it = tab3.begin(); it != tab3.end(); it++)
		std::cout << *it << std::endl;
	
	std::cout << "-------------------------------------------" << std::endl;

	/* COPY CONSTRUTOR */
	ft::vector<std::string>	tab4(tab3);

	std::cout << "COPY CONSTRUCTOR" << std::endl;
	for (ft::vector<std::string>::iterator it = tab4.begin(); it != tab4.end(); it++)
		std::cout << *it << std::endl;
	
	std::cout << "-------------------------------------------" << std::endl;

	/* RANGE CONSTRUCTOR */
	ft::vector<std::string>	tab5(++tab4.begin(), --tab4.end());
	std::cout << "RANGE CONSTURCTOR" << std::endl;
	for (ft::vector<std::string>::iterator it = tab5.begin(); it != tab5.end(); it++)
		std::cout << *it << std::endl;
	
	std::cout << "-------------------------------------------" << std::endl;

	/* OPERAOR = */

	/* BEGIN */
	/* END */
	/* RBEGIN */
	/* REND */
	/* SIZE */

	/* MAX_SIZE */

	/* resize */

	/* capacity */

	/* empty */

	/* reserve */

	/* at */

	/* front */

	/* back */

	/* assign */

	/* push_back */

	/* pop_back */

	/* insert */

	/* erase */

	/* swap */

	/* clear */

	/* get_allocator */

	return 0;
}
