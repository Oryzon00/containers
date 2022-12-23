#pragma once

namespace ft
{

/*------------------------------------------------------------------------------------------------*/

/*  
--- ENABLE_IF --- 
B is true, std::enable_if has a public member typedef type, equal to T; 
otherwise, there is no member typedef.
This metafunction is a convenient way to leverage SFINAE prior to C++20's concepts

"Substitution Failure Is Not An Error"
*/


template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

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
--- IS_INTEGRAL ---
Checks whether T is an integral type. 
Provides the member constant value which is equal to true, if T is the type bool, char, char8_t 
(since C++20), char16_t, char32_t, wchar_t, short, int, long, long long, or any 
implementation-defined extended integer types, including any signed, unsigned, and 
cv-qualified variants. 
Otherwise, value is equal to false.
 */

template <class T> struct is_integral : false_type	{};

// wtf is wchar_t wide char?
// pourquoi l'arg de template est vide? template de template ?
	//pourquoi l'arg de template est ici?
template <> struct is_integral <bool>				: true_type {};	
template <> struct is_integral <char>				: true_type {};	
template <> struct is_integral <wchar_t>			: true_type {};	
template <> struct is_integral <char16_t>			: true_type {};
template <> struct is_integral <char32_t>			: true_type {};	
template <> struct is_integral <int>				: true_type {};	
template <> struct is_integral <long>				: true_type {};	
template <> struct is_integral <long long>			: true_type	{};
template <> struct is_integral <unsigned char>		: true_type {};
template <> struct is_integral <unsigned short>		: true_type {};
template <> struct is_integral <unsigned int>		: true_type {};
template <> struct is_integral <unsigned long>		: true_type {};
template <> struct is_integral <unsigned long long> : true_type {};

/*------------------------------------------------------------------------------------------------*/

};
