#pragma once

#include <memory>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iterator>

#include "iterator.hpp"
#include "type_traits.hpp"
#include "lexicographical_compare.hpp"


namespace ft
{


/*------------------------------------------------------------------------------------------------*/

/*
----- VECTOR -----
std::vector is a sequence container that encapsulates dynamic size arrays.

The elements are stored contiguously, which means that elements can be accessed not only
through iterators, but also using offsets to regular pointers to elements.
This means that a pointer to an element of a vector may be passed to any function
that expects a pointer to an element of an array.
The storage of the vector is handled automatically, being expanded as needed
*/

template < class T, class Allocator = std::allocator<T> >
class vector
{
	
	public:
		/* ---------- MEMBER TYPES ----------- */

		typedef				T											value_type;
		typedef				Allocator									allocator_type;
		typedef typename	allocator_type::reference					reference;
		typedef	typename	allocator_type::const_reference				const_reference;
		typedef	typename	allocator_type::pointer						pointer;
		typedef	typename	allocator_type::const_pointer				const_pointer;
		typedef	typename	ft::random_access_iterator<pointer>			iterator;
		typedef	typename	ft::random_access_iterator<const_pointer>	const_iterator;
		typedef	typename	ft::reverse_iterator<iterator>				reverse_iterator;
		typedef	typename	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef				std::ptrdiff_t								difference_type;	
		typedef				std::size_t									size_type;
	
	private:
		/* ---------- MEMBER VARIABLES ----------- */
		allocator_type	_alloc;
		pointer			_array;
		size_type		_capacity;
		size_type		_size;
	
		
	public:
		/* ---------- CONSTRUCTORS / DESTRUCTOR / COPY ----------- */

		/* DEFAULT CONSTRUCTOR */
		explicit vector(const allocator_type & alloc = allocator_type())	:
			_alloc(alloc), _array(_alloc.allocate(0)), _capacity(0), _size(0)	{}

		/* FILL CONSTRUCTOR */
		explicit vector(size_type n, const value_type & val = value_type(),
						const allocator_type & alloc = allocator_type())	:
			_alloc(alloc), _array(NULL), _capacity(0), _size(0) //0 ou n?
		{
			assign(n, val);
		}

		/* RANGE CONSTRUCTOR */
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			   const allocator_type & alloc = allocator_type())	:
			_alloc(alloc), _array(NULL), _capacity(0), _size(0) //0 ou n?
		{
			assign(first, last);
		}

		/* COPY CONSTRUCTOR */
		vector(const vector & other)	:
			_alloc(other.alloc), _array(NULL), _capacity(0), _size(0) //0 ou n?
		{
			// assign(other.begin(), other.end());
			*this = other;
		}

		/* DESTRUCTOR */
		~vector()
		{
			clear();
			_alloc.deallocate(_array, _capacity);
		}

		/* OPERATOR= */
		vector&	operator=(const vector& other)
		{
			
			assign(other.begin(), other.end());
		}

		/* ---------- ITERATORS ----------- */

		iterator				begin()				{ return iterator(_array); 					}
		const_iterator			begin()		const	{ return const_iterator(_array);			}
		
		iterator				end()				{ return iterator(_array + _size);			}
		const_iterator			end()		const	{ return const_iterator(_array + _size);	}

		reverse_iterator		rbegin()			{ return reverse_iterator(end());			}
		const_reverse_iterator	rbegin()	const	{ return const_reverse_iterator(end());		}

		reverse_iterator		rend()				{ return reverse_iterator(begin());			}
		const_reverse_iterator	rend()		const	{ return const_reverse_iterator(begin());	}

		/* ---------- ALLOCATOR ----------- */
		allocator_type get_allocator()		const	{ return _alloc; }

		/* ---------- CAPACITY ----------- */

		
		size_type	size()		const	{ return _size;				}
		size_type	max_size()	const	{ return _alloc.max_size();	}
		size_type	capacity()	const	{ return _capacity;			}
		bool		empty()		const	{ return _size == 0; 		}

		void	reserve(size_type new_cap)
		{
			if (new_cap > _capacity)
			{
				pointer	new_array = _alloc.allocate(new_cap);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&new_array[i], _array[i]);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.destroy(&_array[i]);
				_alloc.deallocate(_array, _capacity);
				_array = new_array;
				_capacity = new_cap;
			}
		}

		/* ---------- ELEMENT ACCESS ----------- */

		reference		operator[](size_type n)			{ return _array[n]; }
		const_reference	operator[](size_type n)	const	{ return _array[n]; }

		reference		at(size_type n)	
		{
			if (n >= _size)
				throw std::out_of_range("ft::vector::at");
			return _array[n];
		}

		const_reference	at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("ft::vector::at");
			return _array[n];
		}

		reference		front()			{ return _array[0]; }
		const_reference	front() const	{ return _array[0]; }

		reference		back()			{ return _array[_size - 1]; }
		const_reference	back() const	{ return _array[_size - 1]; }

		/* ---------- MODIFIERS ----------- */

		void	assign(size_type n, const value_type & val)
		{
			erase(begin(), end());
			insert(begin(), n, val);
		}

		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last)
		{
			erase(begin(), end());
			insert(begin(), first, last);
		}

		void	resize(size_type n, value_type val = value_type())
		{
			if (n > _size)
				insert(end(), n - _size, val);
			else if (n < _size)
				erase(begin() + n, end());
			else
				;
		}

		void	pop_back()							{ erase(end() - 1); }
		void	push_back(const value_type & val)	{ insert(end(), val); }
		void	clear()								{ erase(begin(), end()); }

		void	swap(vector & other)
		{
			ft::swap(_array, other._array);
			ft::swap(_size, other._size);
			ft::swap(_capacity, other._capacity);
			ft::swap(_alloc, other._alloc);
		}

		iterator	insert(iterator position, const value_type & val)
		{
			insert(position, 1, val);
			return iterator(&_array[std::distance<iterator>(position, begin()) - 1]);
		}

		void		insert(iterator position, size_type n, const value_type & val)
		{	
			while (_size + n > _capacity)
				reserve(_capacity == 0 ? n : _capacity * 2);

			pointer		new_array = _alloc.allocate(_capacity);
			size_type	i = 0;

			for (iterator it = begin(); it != position; it++)
				_alloc.construct(&new_array[i++], *it);
			for (int j = 0; j < n; j++)
				_alloc.construct(&new_array[i++], val);
			for (iterator it = position; it != end(); it++)
				_alloc.construct(&new_array[i++], val);
			for (int k = 0; k < _size; k++)
				_alloc.destroy(&_array[k]);
			_alloc.deallocate(_array, _size);
			_array = new_array;
			_size += n;
		}

		template <class InputIterator> //pb car InputIterator != iterator
		void		insert(iterator position, InputIterator first, InputIterator last)
		{
			difference_type n = std::distance<InputIterator>(first, last);
			while (_size + n > _capacity)
				reserve(_capacity == 0 ? n : _capacity * 2);

			pointer		new_array = _alloc.allocate(_capacity);
			size_type	i = 0;
			
			for (iterator it = begin(); it != position; it++)
				_alloc.construct(&new_array[i++], *it);
			for (iterator it = first; it != last; it++)
				_alloc.construct(&new_array[i++], *it);
			for (iterator it = position; it != end(); it++)
				_alloc.construct(&new_array[i++], *it);
			for (int j = 0; j < _size; j++)
				_alloc.destroy(&_array[j]);
			_alloc.deallocate(_array, _size);
			_array = new_array;
			_size += n;

			
		}

		iterator	erase(iterator position)
		{
			if (position == end())
				return (position);
			return erase(position, position + 1);
		}

		iterator	erase(iterator first, iterator last)
		{
			pointer			new_array = _alloc.allocate(_capacity);
			difference_type	nb = std::distance<iterator>(first, last);
			difference_type	offset = first - begin();
			size_type 		i = 0;

			for (iterator it = begin(); it != first; it++)
				_alloc.construct(&new_array[i++], *it);
			for ( iterator it = last; it != end(); it++)
				_alloc.construct(&new_array[i++], *it);
			for (int j = 0; j < _size; j++)
				_alloc.destroy(&_array[j]);
			_alloc.deallocate(_array, _capacity);
			_array = new_array;
			_size -= nb;
			return (iterator(&_array[offset]));
		}

};


/* ----------  NON MEMBER FUNCTIONS ---------- */

template <class T, class Alloc>
void	swap(vector<T, Alloc> & x, vector<T, Alloc> & y)
{
	x.swap(y);
}

/* RELATIONAL OPERATORS */

template <class T, class Alloc>
  bool operator== (const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
  bool operator!= (const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
{
	return !(lhs == rhs);
}

template <class T, class Alloc>
  bool operator<  (const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
  bool operator<= (const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
{
	return !(rhs < lhs);
}

template <class T, class Alloc>
  bool operator>  (const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
{
	return rhs < lhs;
}

template <class T, class Alloc>
  bool operator>= (const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs)
{
	return !(lhs < rhs);
}




/*------------------------------------------------------------------------------------------------*/
}
