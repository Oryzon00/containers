#pragma once

#include <vector>


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
template < class T, class Container = std::vector<T> >
class stack
{
	public:
	/* ---------- MEMBER TYPES ----------- */
	typedef	T			value_type;
	typedef	Container	container_type;
	typedef	size_t		size_type;

	private:
	/* ---------- MEMBER VARIABLES ----------- */
	container_type	_array;

	public:
	/* ---------- CONSTRUCTORS ----------- */
	explicit	stack(const container_type & cntr = container_type())
	{
		
	}


	/* ---------- OPERATOR OVERLOAD ---------- */	








};











}
