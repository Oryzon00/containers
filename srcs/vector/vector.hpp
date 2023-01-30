#pragma once

#include <memory>
#include <exception>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > class vector
	{

		public:

/*------------------------------------------------------------------------------------------------*/
			/* TYPEDEF */
			typedef	T											value_type;
			typedef	Alloc										allocator_type;
			typedef	allocator_type::reference					reference;
			typedef	allocator_type::const_reference				const_reference;
			typedef	allocator_type::pointer						pointer;
			typedef	allocator_type::const_pointer				const_pointer;
			typedef	random_access_iterator<value_type>			iterator;
			typedef	random_access_iterator<const value_type>	const_iterator;
			typedef	random_access_iterator...					reverse_iterator;
			typedef	random_access_iterator....					const_reverse_iterator;

/*------------------------------------------------------------------------------------------------*/			
		private:
			/* ATTRIBUT MEMBRE */
			T*				_array;
			size_t			_currentsize;
			size_t			_maxSize;
			allocator_type	_allocator

/*------------------------------------------------------------------------------------------------*/
		public:

	};
};
