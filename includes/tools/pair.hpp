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
	/* ---------- MEMBER TYPES ----------- */
	typedef	T1	first_type;
	typedef	T2	second_type;

	/* ---------- MEMBER VARIABLES ----------- */
	T1	first;
	T2	second;

	/* ---------- CONSTRUCTORS ----------- */

	/* Default constructor */
	pair() : first(), second ()		{};

	/* Initialization constructor */
	pair( const T1 & x, const T2 & y )	: first(x), second(y)	{};

	/* Copy constructor */
	template <class U1, class U2>
	pair(const pair <U1, U2> & p) : first(p.first), second(p.second)	{};

	/* ---------- OPERATOR OVERLOAD ---------- */

	/* Operator = */
	pair &	operator=(const pair & p)
	{
		first = p.first;
		second = p.second;
		return (*this);
	}
};

/* ---------- NON MEMBER FUNCTIONS ---------- */

/* Operator == */
template <class T1, class T2>
  bool operator== (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return lhs.first==rhs.first && lhs.second==rhs.second;
}

/* Operator != */
template <class T1, class T2>
  bool operator!= (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return !(lhs==rhs);
}

/* Operator < */
template <class T1, class T2>
  bool operator<  (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
}

/* Operator <= */
template <class T1, class T2>
  bool operator<= (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return !(rhs<lhs);
}

/* Operator > */
template <class T1, class T2>
  bool operator>  (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return rhs<lhs;
}

/* Operator >= */
template <class T1, class T2>
  bool operator>= (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return !(lhs<rhs);
}


/*------------------------------------------------------------------------------------------------*/

/*
----- MAKE_PAIR -----
Construct pair object
Constructs a pair object with its first element set to x and its second element set to y.
*/

template <class T1,class T2>
pair<T1,T2>	make_pair (T1 x, T2 y)
{
	return ( pair<T1,T2> (x, y) );
}

/*------------------------------------------------------------------------------------------------*/

}
