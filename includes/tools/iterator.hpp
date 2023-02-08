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

/*
----- ITERATOR_TAG -----
Empty class to identify the category of an iterator 
*/

struct random_access_iterator_tag {};
struct bidirectional_iterator_tag {};


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
	typedef	ft::random_access_iterator_tag			iterator_category;
};

template <class T>
struct iterator_traits <const T*>
{
	typedef	std::ptrdiff_t							difference_type;
	typedef	T										value_type;
	typedef	const T*								pointer;
	typedef	const T&								reference;
	typedef	ft::random_access_iterator_tag			iterator_category;
};


/*------------------------------------------------------------------------------------------------*/

/*
----- REVERSE_ITERATOR -----
This class reverses the direction in which a bidirectional or random-access iterator iterates
through a range.
*/

template <class Iterator>
class reverse_iterator : public
	  iterator<typename iterator_traits<Iterator>::iterator_category,
	  		   typename iterator_traits<Iterator>::value_type,
			   typename iterator_traits<Iterator>::difference_type,
			   typename iterator_traits<Iterator>::pointer,
			   typename iterator_traits<Iterator>::reference>
{
	
	protected:
		/* ---------- MEMBER VARIABLES ----------- */
		Iterator	current;
	
	public:
		/* ---------- MEMBER TYPES ----------- */
		typedef				Iterator									iterator_type;
		typedef	typename	iterator_traits<Iterator>::difference_type	difference_type;
		typedef	typename	iterator_traits<Iterator>::reference		reference;
		typedef	typename	iterator_traits<Iterator>::pointer			pointer;

		/* ---------- CONSTRUCTORS ----------- */

		/* DEFAULT CONSTRUCTOR */
		reverse_iterator()									current()				{};

		/* INITIALIZATION CONSTRUCTOR */
		explicit	reverse_iterator(Iterator it)			current(it)				{};

		/* COPY CONSTRUCTOR */
		template <class U>
		reverse_iterator(const reverse_iterator<U> & other)	current(other.current)	{};

		/* ---------- OPERATOR ---------- */
	
		/* ACCESSORS */
		Iterator	base() const		{ return (current) };
		reference	operator*() const	{ Iterator	tmp = current; return (*--tmp); }
		pointer		operator->() const	{ Iterator	tmp = current; return &(operator*()); }
		reference	operator[](difference_type n) const	{ return current[-n - 1]; }

		/* PRE INCREMENT OPERATORS */
		reverse_iterator&	operator++()	{ --current; return *this; }
		reverse_iterator&	operator--()	{ ++current; return *this; }

		/* POST INCREMENT OPERATORS */
		reverse_iterator	operator++(int)	{ reverse_iterator tmp = *this; --current; return tmp; }
		reverse_iterator	operator--(int)	{ reverse_iterator tmp = *this; ++current; return tmp; }

		reverse_iterator
		operator+ (difference_type n) const	{ return reverse_iterator(current - n); }
		reverse_iterator&
		operator+=(difference_type n)		{ current -= n; return *this; 			}

		reverse_iterator
		operator- (difference_type n) const	{ return reverse_iterator(current + n); }
		reverse_iterator&
		operator-=(difference_type n)		{ current += n; return *this;			}

};

/* ---------- COMPARAISON OPERATORS ---------- */

template <class Iterator1, class Iterator2>
 bool	operator==(const ft::reverse_iterator<Iterator1> & lhs,
 				   const ft::reverse_iterator<Iterator2> & rhs)
{
	return lhs.base() == rhs.base();
}

template <class Iterator1, class Iterator2>
 bool	operator!=(const ft::reverse_iterator<Iterator1> & lhs,
 				   const ft::reverse_iterator<Iterator2> & rhs)
{
	return lhs.base() != rhs.base();
}

template <class Iterator1, class Iterator2>
 bool	operator> (const ft::reverse_iterator<Iterator1> & lhs,
 				   const ft::reverse_iterator<Iterator2> & rhs)
{
	return lhs.base() > rhs.base();
}

template <class Iterator1, class Iterator2>
 bool	operator>=(const ft::reverse_iterator<Iterator1> & lhs,
 				   const ft::reverse_iterator<Iterator2> & rhs)
{
	return lhs.base() >= rhs.base();
}

template <class Iterator1, class Iterator2>
 bool	operator< (const ft::reverse_iterator<Iterator1> & lhs,
 				   const ft::reverse_iterator<Iterator2> & rhs)
{
	return lhs.base() < rhs.base();
}

template <class Iterator1, class Iterator2>
 bool	operator<=(const ft::reverse_iterator<Iterator1> & lhs,
 				   const ft::reverse_iterator<Iterator2> & rhs)
{
	return lhs.base() <= rhs.base();
}

template <class Iterator>
reverse_iterator<Iterator>
	operator+(typename reverse_iterator<Iterator>::difference_type n,
									  const reverse_iterator<Iterator> & it)
{
	return ( reverse_iterator<Iterator>(it.base() - n ) );
}

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type
	operator-(const reverse_iterator<Iterator1> & lhs,
			  const reverse_iterator<Iterator2> & rhs)
{
	return ( rhs.base() - lhs.base() );
}














	
}
