#pragma once

#include "iterator.hpp"

namespace ft
{

/*------------------------------------------------------------------------------------------------*/

/* 
----- LEXICOGRAPHICAL_COMPARE ----- 
Checks if the first range [first1, last1) is lexicographically less than the 
second range [first2, last2). 
*/

template <class InputIt1, class InputIt2>
bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
	{
		if (*first1 < *first2)
			return true;
		if (*first2 < *first1)
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template <class InputIt1, class InputIt2, class Compare>
bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2,
								Compare comp)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
	{
		if (comp(*first1, *first2))
			return true;
		if (comp(*first2, *first1))
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}	

/*
----- SWAP -----
*/

template <class T>
void	swap(T & a, T & b)
{
	T	tmp(a); // tmp = a (a voir sur les swaps de vector et les iters)
	a = b;
	b = tmp;
}

/*------------------------------------------------------------------------------------------------*/

/* ----- DISTANCE ------ */

template<class InputIterator>
typename ft::iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last)
{
	typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
	while (first != last)
	{
		first++;
		rtn++;
	}
	return (rtn);
}

/*------------------------------------------------------------------------------------------------*/

}
