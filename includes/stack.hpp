#pragma once

#include "vector.hpp"


namespace ft
{

/*------------------------------------------------------------------------------------------------*/

/* 
----- STACK-----
LIFO stack
Stacks are a type of container adaptor, specifically designed to operate in a 
LIFO context (last-in first-out), where elements are inserted and extracted only from 
one end of the container.
*/

/* Change std::vector by ft::vector */
template < class T, class Container = ft::vector<T> >
class stack
{
	public:
	/* ---------- MEMBER TYPES ----------- */
	typedef	T			value_type;
	typedef	Container	container_type;
	typedef	size_t		size_type;

	protected:
	/* ---------- MEMBER VARIABLES ----------- */
	container_type	c;

	public:
	/* ---------- CONSTRUCTORS ----------- */
	explicit	stack(const container_type & cntr = container_type())	:	_array(cntr)	{}


	/* ---------- OPERATOR ---------- */	
	stack &		operator=(const stack & other)
	{
		c = other.c;
		return (*this);
	}

	/* ---------- MEMBER FUNCTIONS ---------- */
	bool				empty() const				{ return c.empty(); }
	size_type			size() const				{ return c.size();	}
	value_type &		top()						{ return c.back();	}
	const value_type &	top() const					{ return c.back();	}
	void				push(const value_type & x)	{ c.push_back(x);	}
	void				pop()						{ c.pop_back();		}

};

/* ---------- NON MEMBER FUNCTIONS ---------- */

template <class T, class Container>
bool operator==(const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return ( lhs.c == rhs.c);
}

template <class T, class Container>
bool operator!=(const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return ( lhs.c != rhs.c);
}

template <class T, class Container>
bool operator< (const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return ( lhs.c < rhs.c);
}


template <class T, class Container>
bool operator> (const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return ( lhs.c > rhs.c);
}

template <class T, class Container>
bool operator>=(const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return ( lhs.c >= rhs.c);
}

template <class T, class Container>
bool operator<=(const stack<T, Container> & lhs, const stack<T, Container> & rhs)
{
	return ( lhs.c <= rhs.c);
}

/*------------------------------------------------------------------------------------------------*/

}
