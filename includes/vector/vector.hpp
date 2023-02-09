#pragma once

#include <memory>
#include <exception>
#include "iterator.hpp"

namespace ft
{


/*------------------------------------------------------------------------------------------------*/

/*
----- VECTOR -----
std::vector is a sequence container that encapsulates dynamic size arrays.

The elements are stored contiguously, which means that elements can be accessed not only
through iterators, but also using offsets to regular pointers to elements.
This means that a pointer to an element of a vector may be passed to any function
that expects a pointer to an element of an array.
The storage of the vector is handled automatically, being expanded as needed
*/

//Iterator invalidation???

template < class T, class Allocator = std::allocator<T> >
class vector
{
	
	public:
		/* ---------- MEMBER TYPES ----------- */

		typedef				T											value_type;
		typedef				Allocator									allocator_type;
		typedef typename	allocator_type::reference					reference;
		typedef	typename	allocator_type::const_reference				const_reference;
		typedef	typename	allocator_type::pointer						pointer;
		typedef	typename	allocator_type::const_pointer				const_pointer;
		typedef	typename	ft::random_access_iterator<pointer>			iterator;
		typedef	typename	ft::random_access_iterator<const_pointer>	const_iterator;
		typedef	typename	ft::reverse_iterator<iterator>				reverse_iterator;
		typedef	typename	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef				std::ptrdiff_t								difference_type;	
		typedef				std::size_t									size_type;
		
		
		

	
	private:
		/* ---------- MEMBER VARIABLES ----------- */
		Allocator	_alloc;
		pointer		_array;
		size_type	_allocated;
		size_type	_size;
	
	public:
		/* ---------- CONSTRUCTORS / DESTRUCTOR ----------- */


};


/* ----------  NON MEMBER FUNCTIONS ---------- */









/*------------------------------------------------------------------------------------------------*/


/*
----- BOOL SPECIALIZATION -----

*/




template < class Allocator >
class vector <bool, Allocator >
{
	/* ---------- MEMBER VARIABLES ----------- */

	/* ---------- MEMBER TYPES ----------- */


	/* ---------- CONSTRUCTORS / DESTRUCTOR ----------- */


};
};
