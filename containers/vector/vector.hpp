#pragma once

#include <memory>

template < class T > class vector_it;

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > class vector
	{

		public:

/*------------------------------------------------------------------------------------------------*/
			/* TYPEDEF */
			typedef	T								value_type;
			typedef	Alloc							allocator_type;
			typedef	allocator_type::reference		reference;
			typedef	allocator_type::const_reference	const_reference;
			typedef	allocator_type::pointer			pointer;
			typedef	allocator_type::const_pointer	const_pointer;
			typedef	

/*------------------------------------------------------------------------------------------------*/			
		private:

		protected:

	};
};
