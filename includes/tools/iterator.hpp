#pragma once

#include <cstddef>

namespace ft
{

/*------------------------------------------------------------------------------------------------*/

/*
----- ITERATOR -----
std::iterator is the base class provided to simplify definitions of 
the required types for iterators
*/

template < class Category, class T,
	class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
struct iterator
{
	/* MEMBER TYPES */
	typedef	Category	iterator_category;
	typedef	T			value_type;
	typedef	Distance	difference_type;
	typedef	Pointer		pointer;
	typedef	Reference	reference;

	
};


/*------------------------------------------------------------------------------------------------*/



















	
}
