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

template < class Category, class T,
	class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
struct const_iterator
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
		typedef				Iterator										iterator_type;
		typedef	typename	iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef	typename	iterator_traits<Iterator>::value_type			value_type;
		typedef	typename	iterator_traits<Iterator>::difference_type		difference_type;
		typedef	typename	iterator_traits<Iterator>::pointer				pointer;
		typedef	typename	iterator_traits<Iterator>::reference			reference;

		/* ---------- CONSTRUCTORS / DESTRUCTOR ----------- */

		/* DEFAULT CONSTRUCTOR */	
		reverse_iterator()									:	current()				{}

		/* INITIALIZATION CONSTRUCTOR */
		explicit	reverse_iterator(Iterator it)			:	current(it)				{}

		/* COPY CONSTRUCTOR */
		template <class U>
		reverse_iterator(const reverse_iterator<U> & other)	:	current(other.base())	{}

		/* DESTRUCTOR */
		~reverse_iterator()																{}

		/* ---------- OPERATOR ---------- */

		template <class U>
		reverse_iterator&
		operator=(const reverse_iterator<U> & other)	{ current = other.base(); return *this; }
	
		/* ACCESSORS */
		Iterator	base() const		{ return current; }
		reference	operator*() const	{ Iterator	tmp = current; return (*--tmp); }
		pointer		operator->() const	{ return &(operator*()); }
		reference	operator[](difference_type n) const	{ return current[-n - 1]; }

		/* PRE INCREMENT OPERATORS */
		reverse_iterator&	operator++()	{ --current; return *this; }
		reverse_iterator&	operator--()	{ ++current; return *this; }

		/* POST INCREMENT OPERATORS */
		reverse_iterator	operator++(int)	{ reverse_iterator tmp = *this; --current; return tmp; }
		reverse_iterator	operator--(int)	{ reverse_iterator tmp = *this; ++current; return tmp; }

		/* ARITHMETIC OPERATORS */
		reverse_iterator
		operator+ (difference_type n) const	{ return reverse_iterator(current - n); }
		reverse_iterator&
		operator+=(difference_type n)		{ current -= n; return *this; 			}

		reverse_iterator
		operator- (difference_type n) const	{ return reverse_iterator(current + n); }
		reverse_iterator&
		operator-=(difference_type n)		{ current += n; return *this;			}

};

/* ----------  NON MEMBER FUNCTIONS ---------- */

/* COMPARAISON OPERATORS */

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

/* ARITHMETIC OPERATORS */

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

/*------------------------------------------------------------------------------------------------*/

/*
----- RANDOM ACCESS ITERATOR -----
A LegacyRandomAccessIterator is a LegacyBidirectionalIterator that can be moved to point
to any element in constant time.
If a LegacyRandomAccessIterator it originates from a Container, then it's value_type is
the same as the container's, so dereferencing (*it) obtains the container's value_type.
A pointer to an element of an array satisfies all requirements of LegacyRandomAccessIterator.
*/

template  <class Iterator>
class random_access_iterator : public
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
		typedef				Iterator										iterator_type;
		typedef	typename	iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef	typename	iterator_traits<Iterator>::value_type			value_type;
		typedef	typename	iterator_traits<Iterator>::difference_type		difference_type;
		typedef	typename	iterator_traits<Iterator>::pointer				pointer;
		typedef	typename	iterator_traits<Iterator>::reference			reference;

		/* ---------- CONSTRUCTORS / DESTRUCTOR ----------- */

		/* DEFAULT CONSTRUCTOR */
		random_access_iterator()										: current()				{}

		/* INITIALIZATION CONSTRUCTOR */
		explicit	random_access_iterator(Iterator it)					: current(it)			{}

		/* COPY CONSTRUCTOR */
		template <class U>
		random_access_iterator(const random_access_iterator<U> & other)	: current(other.base())	{}

		/* DESTRUCTOR */
		~random_access_iterator()																{}

		/* ---------- OPERATOR ---------- */

		template <class U>
		random_access_iterator&
		operator=(const random_access_iterator<U> & other)	{ current = other.base(); return *this; }

		/* ACCESSORS */
		Iterator	base() const						{ return current;			}
		reference	operator* () const					{ return *current;			}
		pointer		operator->() const					{ return &(operator*());	}
		reference	operator[](difference_type n) const	{ return current[n];		}

		/* PRE INCREMENT OPERATORS */
		random_access_iterator&	operator++()	{ ++current; return *this; }
		random_access_iterator&	operator--()	{ --current; return *this; }


		/* POST INCREMENT OPERATORS */
		random_access_iterator
			operator++(int)	{ random_access_iterator tmp = *this; ++current; return tmp; }
		random_access_iterator
			operator--(int)	{ random_access_iterator tmp = *this; --current; return tmp; }

		/* ARITHMETIC OPERATORS */
		random_access_iterator
			operator+ (difference_type n) const	{ return random_access_iterator(current + n);	}
		random_access_iterator&
			operator+=(difference_type n)		{ current += n; return *this;					}

		random_access_iterator
			operator- (difference_type n) const	{ return random_access_iterator(current - n);	}
		random_access_iterator&
			operator-=(difference_type n)		{ current -= n; return *this;					}
		

};

/* ----------  NON MEMBER FUNCTIONS ---------- */

/* COMPARAISON OPERATORS */

template <class Iterator1, class Iterator2>
 bool	operator==(const ft::random_access_iterator<Iterator1> & lhs,
 				   const ft::random_access_iterator<Iterator2> & rhs)
{
	return lhs.base() == rhs.base();
}

template <class Iterator1, class Iterator2>
 bool	operator!=(const ft::random_access_iterator<Iterator1> & lhs,
 				   const ft::random_access_iterator<Iterator2> & rhs)
{
	return lhs.base() != rhs.base();
}

template <class Iterator1, class Iterator2>
 bool	operator> (const ft::random_access_iterator<Iterator1> & lhs,
 				   const ft::random_access_iterator<Iterator2> & rhs)
{
	return lhs.base() > rhs.base();
}

template <class Iterator1, class Iterator2>
 bool	operator>=(const ft::random_access_iterator<Iterator1> & lhs,
 				   const ft::random_access_iterator<Iterator2> & rhs)
{
	return lhs.base() >= rhs.base();
}

template <class Iterator1, class Iterator2>
 bool	operator< (const ft::random_access_iterator<Iterator1> & lhs,
 				   const ft::random_access_iterator<Iterator2> & rhs)
{
	return lhs.base() < rhs.base();
}

template <class Iterator1, class Iterator2>
 bool	operator<=(const ft::random_access_iterator<Iterator1> & lhs,
 				   const ft::random_access_iterator<Iterator2> & rhs)
{
	return lhs.base() <= rhs.base();
}

/* ARITHMETIC OPERATORS */

template <class Iterator>
random_access_iterator<Iterator>
operator+(typename random_access_iterator<Iterator>::difference_type n,
		  const random_access_iterator<Iterator> & it)
{
	return ( random_access_iterator<Iterator>(it.base() + n ) );
}

template <class Iterator1, class Iterator2>
typename random_access_iterator<Iterator1>::difference_type
	operator-(const random_access_iterator<Iterator1> & lhs,
			  const random_access_iterator<Iterator2> & rhs)
{
	return ( lhs.base() - rhs.base() );
}


/*------------------------------------------------------------------------------------------------*/

/*
----- BIDIRRECTIONNAL ITERATOR -----
A LegacyBidirectionalIterator is a LegacyForwardIterator that can be moved in both directions 
(i.e. incremented and decremented).
If a LegacyBidirectionalIterator it originates from a Container, then it's value_type is
the same as the container's, so dereferencing (*it) obtains the container's value_type.
*/

template  <class Iterator>
class bidirectional_iterator : public
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
		typedef				Iterator										iterator_type;
		typedef	typename	iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef	typename	iterator_traits<Iterator>::value_type			value_type;
		typedef	typename	iterator_traits<Iterator>::difference_type		difference_type;
		typedef	typename	iterator_traits<Iterator>::pointer				pointer;
		typedef	typename	iterator_traits<Iterator>::reference			reference;

		/* ---------- CONSTRUCTORS / DESTRUCTOR ----------- */

		/* DEFAULT CONSTRUCTOR */
		bidirectional_iterator()										: current()				{}

		/* INITIALIZATION CONSTRUCTOR */
		explicit	bidirectional_iterator(Iterator it)					: current(it)			{}

		/* COPY CONSTRUCTOR */
		template <class U>
		bidirectional_iterator(const bidirectional_iterator<U> & other)	: current(other.base())	{}

		/* DESTRUCTOR */
		~bidirectional_iterator()																{}

		/* ---------- OPERATOR ---------- */

		template <class U>
		bidirectional_iterator&
		operator=(const bidirectional_iterator<U> & other)	{ current = other.base(); return *this; }

		/* ACCESSORS */
		Iterator	base() const						{ return current;			}
		reference	operator* () const					{ return *current;			}
		pointer		operator->() const					{ return &(operator*());	}

		/* PRE INCREMENT OPERATORS */
		bidirectional_iterator&	operator++()	{ ++current; return *this; }
		bidirectional_iterator&	operator--()	{ --current; return *this; }

		/* POST INCREMENT OPERATORS */
		bidirectional_iterator
			operator++(int)	{ bidirectional_iterator tmp = *this; ++current; return tmp; }
		bidirectional_iterator
			operator--(int)	{ bidirectional_iterator tmp = *this; --current; return tmp; }

};

	
}
