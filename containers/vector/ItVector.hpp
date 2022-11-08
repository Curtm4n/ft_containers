/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItVector.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:50:11 by cdapurif          #+#    #+#             */
/*   Updated: 2022/11/08 18:24:27 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITVECTOR_HPP
# define ITVECTOR_HPP

# include <cstddef>

namespace ft
{
    template <class T>
    class ItVector
    {
        
        public:

            typedef T           value_type;
            typedef T*          pointer;
            typedef T&          reference;
            typedef const T&    const_reference;

            typedef std::ptrdiff_t  difference_type;

            ItVector(pointer ptr = pointer()) : _ptr(ptr)                   {}
            ItVector(const ItVector<T>& x) : _ptr(x._ptr)                   {}
            ItVector<T>&    operator=(const ItVector<T>& x)                 { this->_ptr = x._ptr; }
            ~ItVector(void)                                                 {}

            //THIS ALLOW CONVERSION FROM ITERATOR TO CONST ITERATOR
            operator ItVector<const T>() const
            {
                return (ItVector<const T>(this->_ptr));
            }

            pointer getPointer(void) const  {return (_ptr); }
            
            reference       operator*(void) const                   { return (*_ptr); }
            pointer         operator->(void) const                  { return (_ptr); }
            ItVector<T>     operator+(difference_type x)            { return (_ptr + x); }
            ItVector<T>     operator-(difference_type x)            { return (_ptr - x); }
            ItVector<T>&    operator++(void)                        { _ptr++; return (*this); }
            ItVector<T>&    operator--(void)                        { _ptr--; return (*this); }
            ItVector<T>&    operator++(int)                         { ItVector<T>   tmp(*this); _ptr++; return (tmp._ptr); } //JUST CHANGE return (tmp) to return (tmp._ptr)
            ItVector<T>&    operator--(int)                         { ItVector<T>   tmp(*this); _ptr--; return (tmp._ptr); }
            void            operator+=(difference_type n)           { _ptr += n; }
            void            operator-=(difference_type n)           { _ptr -= n; }
            reference       operator[](difference_type n)           { return (_ptr[n]); }

        private:

            pointer _ptr;
    };

    template <class T>
        bool operator==(const ItVector<T>& x, const ItVector<T>& y)
        {
            return (x.getPointer() == y.getPointer());
        }

    template <class T, class U>
        bool operator==(const ItVector<T>& x, const ItVector<U>& y)     //I HAVE TO DOUBLE CHECK THAT (should allow comparison between const and non const)
        {
            return (x.getPointer() == y.getPointer());
        }

    template <class T>
        bool operator!=(const ItVector<T>& x, const ItVector<T>& y)
        {
            return (x.getPointer() != y.getPointer());
        }

    template <class T>
        bool operator<(const ItVector<T>& x, const ItVector<T>& y)
        {
            return (x.getPointer() < y.getPointer());
        }

    template <class T>
        bool operator>(const ItVector<T>& x, const ItVector<T>& y)
        {
            return (x.getPointer() > y.getPointer());
        }

    template <class T>
        bool operator<=(const ItVector<T>& x, const ItVector<T>& y)
        {
            return (x.getPointer() <= y.getPointer());
        }

    template <class T>
        bool operator>=(const ItVector<T>& x, const ItVector<T>& y)
        {
            return (x.getPointer() >= y.getPointer());
        }

    template <class T>
        ItVector<T> operator+(const ItVector<T>& x, const ItVector<T>& y)
        {
            return (x.getPointer() + y.getPointer());
        }

    template <class T>
        ItVector<T> operator+(typename ItVector<T>::difference_type x, const ItVector<T>& y)
        {
            return (x + y.getPointer());
        }

    template <class T>
        ItVector<T> operator-(const ItVector<T>& x, const ItVector<T>& y)
        {
            return (x.getPointer() - y.getPointer());
        }

    template <class T>
        ItVector<T> operator-(typename ItVector<T>::difference_type x, const ItVector<T>& y)
        {
            return (x - y.getPointer());
        }
}

#endif