#pragma once

namespace ft
{

/*------------------------------------------------------------------------------------------------*/

/*
----- PAIR -----
pair is a class template that provides a way to store two heterogeneous objects as a single unit. 
A pair is a specific case of a std::tuple with two elements.
*/

template <class T1, class T2>
struct pair
{
	typedef	T1	first_type;
	typedef	T2	second_type;
	T1	first;
	T2	second;

	/* Default constructor */
	pair() : first(), second ()		{};

	/* Initialization constructor */
	pair( const T1 & x, const T2 & y )	: first(x), second(y)	{};


	/* Copy constructor */
	// template dans template ? mmhhh.....
	template <class U1, class U2>
	pair(const pair <U1, U2> & p) : first(p.U1), second(p.U2)	{};




};





/*------------------------------------------------------------------------------------------------*/

/*
----- MAKE_PAIR -----

*/




}
