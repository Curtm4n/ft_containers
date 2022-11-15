/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItVector.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:50:11 by cdapurif          #+#    #+#             */
/*   Updated: 2022/11/15 18:22:54 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITVECTOR_HPP
# define ITVECTOR_HPP

# include <cstddef>
# include <ostream>

namespace ft
{
    template <class T>
    class ItVector
    {
        
        public:

            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef std::ptrdiff_t                  difference_type;
            typedef std::random_access_iterator_tag iterator_category;

            ItVector(pointer ptr = pointer()) : _ptr(ptr)                   {}
            ItVector(const ItVector<T>& x) : _ptr(x._ptr)                   {}
            ItVector<T>&    operator=(const ItVector<T>& x)                 { this->_ptr = x._ptr; return (*this); }
            ~ItVector(void)                                                 {}

            //THIS ALLOW CONVERSION FROM ITERATOR TO CONST ITERATOR
            operator ItVector<const T>() const
            {
                return (ItVector<const T>(this->_ptr));
            }

            pointer getPointer(void) const  { return (_ptr); }
            
            reference       operator*(void) const                   { return (*_ptr); }
            pointer         operator->(void) const                  { return (_ptr); }
            ItVector<T>     operator+(difference_type n) const      { return (_ptr + n); }
            ItVector<T>     operator-(difference_type n) const      { return (_ptr - n); }
            ItVector<T>&    operator++(void)                        { _ptr++; return (*this); }
            ItVector<T>&    operator--(void)                        { _ptr--; return (*this); }
            ItVector<T>     operator++(int)                         { ItVector<T>   tmp(*this); _ptr++; return (tmp); }
            ItVector<T>     operator--(int)                         { ItVector<T>   tmp(*this); _ptr--; return (tmp); }
            ItVector<T>&    operator+=(difference_type n)           { _ptr += n; return (*this); }
            ItVector<T>&    operator-=(difference_type n)           { _ptr -= n; return (*this); }
            reference       operator[](difference_type n)           { return (*(_ptr + n)); }

        private:

            pointer _ptr;
    };

    template <class T>
    bool operator==(const ItVector<T>& x, const ItVector<T>& y)
    {
        return (x.getPointer() == y.getPointer());
    }

    template <class T, class U>
    bool operator==(const ItVector<T>& x, const ItVector<U>& y)
    {
        return (x.getPointer() == y.getPointer());
    }

    template <class T>
    bool operator!=(const ItVector<T>& x, const ItVector<T>& y)
    {
        return (x.getPointer() != y.getPointer());
    }

    template <class T, class U>
    bool operator!=(const ItVector<T>& x, const ItVector<U>& y)
    {
        return (x.getPointer() != y.getPointer());
    }

    template <class T>
    bool operator<(const ItVector<T>& x, const ItVector<T>& y)
    {
        return (x.getPointer() < y.getPointer());
    }

    template <class T, class U>
    bool operator<(const ItVector<T>& x, const ItVector<U>& y)
    {
        return (x.getPointer() < y.getPointer());
    }

    template <class T>
    bool operator>(const ItVector<T>& x, const ItVector<T>& y)
    {
        return (x.getPointer() > y.getPointer());
    }

    template <class T, class U>
    bool operator>(const ItVector<T>& x, const ItVector<U>& y)
    {
        return (x.getPointer() > y.getPointer());
    }

    template <class T>
    bool operator<=(const ItVector<T>& x, const ItVector<T>& y)
    {
        return (x.getPointer() <= y.getPointer());
    }

    template <class T, class U>
    bool operator<=(const ItVector<T>& x, const ItVector<U>& y)
    {
        return (x.getPointer() <= y.getPointer());
    }

    template <class T>
    bool operator>=(const ItVector<T>& x, const ItVector<T>& y)
    {
        return (x.getPointer() >= y.getPointer());
    }

    template <class T, class U>
    bool operator>=(const ItVector<T>& x, const ItVector<U>& y)
    {
        return (x.getPointer() >= y.getPointer());
    }

    template <class T>
    ItVector<T> operator+(typename ItVector<T>::difference_type x, const ItVector<T>& y)
    {
        return (x + y.getPointer());
    }

    template <class T>
    typename ItVector<T>::difference_type operator-(const ItVector<T>& x, const ItVector<T>& y)
    {
        return (x.getPointer() - y.getPointer());
    }

    template <class T, class U>
    typename ItVector<T>::difference_type operator-(const ItVector<T>& x, const ItVector<U>& y)
    {
        return (x.getPointer() - y.getPointer());
    }

    template <class T>
    std::ostream &  operator<<(std::ostream & o, const ItVector<T>& x)
    {
        o << x.getPointer();
        return (o);
    }
}

#endif