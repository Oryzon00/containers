#pragma once

#include <cstddef>
#include <iterator>

namespace ft
{

/*------------------------------------------------------------------------------------------------*/

/* 
----- ITERATOR_TRAITS ----- 
std::iterator_traits is the type trait class that provides uniform interface to the properties 
of LegacyIterator types. 
This makes it possible to implement algorithms only in terms of iterators.
*/

template <class Iter>
struct iterator_traits
{
	typedef	typename Iter::difference_type			difference_type;
	typedef	typename Iter::value_type				value_type;
	typedef	typename Iter::pointer					pointer;
	typedef	typename Iter::reference				reference;
	typedef	typename Iter::iterator_category		iterator_category;
};

template <class T>
struct iterator_traits <T*>
{
	typedef	std::ptrdiff_t							difference_type;
	typedef	T										value_type;
	typedef	T*										pointer;
	typedef	T&										reference;
	typedef	std::random_access_iterator_tag			iterator_category;
};

template <class T>
struct iterator_traits <const T*>
{
	typedef	std::ptrdiff_t							difference_type;
	typedef	T										value_type;
	typedef	const T*								pointer;
	typedef	const T&								reference;
	typedef	std::random_access_iterator_tag			iterator_category;
};


/*------------------------------------------------------------------------------------------------*/





}
