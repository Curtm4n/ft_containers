/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItVector.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:50:11 by cdapurif          #+#    #+#             */
/*   Updated: 2022/11/07 15:50:26 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITVECTOR_HPP
# define ITVECTOR_HPP

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

            ItVector(pointer ptr = pointer()) : _ptr(ptr)                   {}
            ItVector(const Itvector<T>& x) : _ptr(x._ptr)                   {}
            ItVector<T>&    operator=(const ItVector<T>& x) : _ptr(x._ptr)  {}
            ~ItVector(void)                                                 {}

            bool            operator==(const ItVector<T>& x) const  { return (this->_ptr == x._ptr); }
            bool            operator!=(const ItVector<T>& x) const  { return (this->_ptr != x._ptr); }
            reference       operator*(void) const                   { return (*_ptr); }
            pointer         operator->(void) const                  { return (_ptr); }         //Not sure for this one, a bit tricky
            ItVector<T>&    operator++(void)                        { _ptr++; return (*this); }
            ItVector<T>&    operator--(void)                        { _ptr--; return (*this); }
            ItVector<T>&    operator++(int)                         { ItVector<T>   tmp(*this); _ptr++; return (tmp); }
            ItVector<T>&    operator--(int)                         { ItVector<T>   tmp(*this); _ptr--; return (tmp); }

        private:

            pointer _ptr;
    };
}

#endif