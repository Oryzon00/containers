#pragma once

namespace ft
{

/*------------------------------------------------------------------------------------------------*/

/*  
----- ENABLE_IF ----- 
If B is true, std::enable_if has a public member typedef type, equal to T; 
otherwise, there is no member typedef.
This metafunction is a convenient way to leverage SFINAE prior to C++20's concepts

"Substitution Failure Is Not An Error"
*/


template <bool B, class T = void>
struct enable_if {};
 
template <class T>
struct enable_if<true, T>
{ 
	typedef T type;
};

/*------------------------------------------------------------------------------------------------*/

/* Operator type () {} --> sert pour les conversions 
explicites et implicites de l'object vers le type */

struct true_type
{
	static const bool	value = true;
	operator bool () { return (value); }
};

struct false_type
{
	static const bool	value = false;
	operator bool () { return (value); }
};

/*------------------------------------------------------------------------------------------------*/

/*
----- REMOVE_CV -----
Provides the member typedef type which is the same as T, except that its topmost 
const and/or volatil qualifiers are removed.
*/

template <class T> struct remove_cv
{
	typedef T	type;
};

template <class T> struct remove_cv <const T>
{
	typedef T	type;
};

template <class T> struct remove_cv <volatile T>
{
	typedef T	type;
};

template <class T> struct remove_cv <const volatile T>
{
	typedef T	type;
};


/*------------------------------------------------------------------------------------------------*/

/* 
----- IS_INTEGRAL -----
Checks whether T is an integral type. 
Provides the member constant value which is equal to true, if T is the type bool, char, char8_t 
(since C++20), char16_t, char32_t, wchar_t, short, int, long, long long, or any 
implementation-defined extended integer types, including any signed, unsigned, and 
cv-qualified variants. 
Otherwise, value is equal to false.
 */

template <class T> struct is_integral_base					: ft::false_type	{};

template <> struct is_integral_base <bool>					: ft::true_type		{};
template <> struct is_integral_base <short>					: ft::true_type 	{};	
template <> struct is_integral_base <char>					: ft::true_type 	{};	
template <> struct is_integral_base <wchar_t>				: ft::true_type 	{};	
// template <> struct is_integral_base <char16_t>				: ft::true_type 	{};
// template <> struct is_integral_base <char32_t>				: ft::true_type 	{};	
template <> struct is_integral_base <int>					: ft::true_type 	{};	
template <> struct is_integral_base <long>					: ft::true_type 	{};	
template <> struct is_integral_base <long long>				: ft::true_type		{};
template <> struct is_integral_base <unsigned char>			: ft::true_type 	{};
template <> struct is_integral_base <unsigned short>		: ft::true_type 	{};
template <> struct is_integral_base <unsigned int>			: ft::true_type 	{};
template <> struct is_integral_base <unsigned long>			: ft::true_type 	{};
template <> struct is_integral_base <unsigned long long>	: ft::true_type 	{};

template <class T> struct is_integral	: is_integral_base <typename ft::remove_cv<T>::type>	{};
/*------------------------------------------------------------------------------------------------*/

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
};
