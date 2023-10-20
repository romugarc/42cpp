/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:59 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/17 17:06:01 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

template< typename T >
class	Array {
	private:
		T *_array;
		unsigned int _size;
	public:
		Array( void ) : _array(NULL), _size(0) {};
		Array( unsigned int n ) : _array(new T[n]), _size(n) {};
		Array( Array const & src ) : _array(new T[src.size()]), _size(src.size()) { 
			std::cout << &this->_array << " copy " << &src._array << std::endl;
			if (this->size() > 0)
			{
				for (unsigned int i = 0; i < src.size(); i++)
					this->_array[i] = src._array[i];
			}
		};
		~Array() {
			delete [] this->_array;
		};

		Array &operator=( Array const &rhs ) {
			std::cout << &this->_array << " = " << &rhs._array << std::endl;
			if (this->size() > 0)
			{
				for (unsigned int i = 0; i < rhs.size(); i++)
					this->_array[i] = rhs._array[i];
			}
			return *this;
		};

		T &operator[]( unsigned int const &index ) {
			if (index > this->size() - 1)
				throw OutOfBoundsException();
			else
				return (this->_array[index]);
		};

		T const &operator[]( unsigned int const &index ) const {
			std::cout << "const" << std::endl;
			if (index > this->size() - 1)
				throw OutOfBoundsException();
			else
				return (this->_array[index]);
		};

		unsigned int size( void ) const {
			return (this->_size);	
		};

		class	OutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Index is out of bounds for this array");
				}
		};

};

#endif