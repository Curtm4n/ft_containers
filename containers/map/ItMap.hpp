/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItMap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:15:50 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/06 14:59:06 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITMAP_HPP
# define ITMAP_HPP

# include "../../utils/utility.hpp"

# include <stddef>

namespace ft
{
    template <class Key, class T>               //NEED FULL CHECK (PROBABLY FALSE, SIMPLE COPY OF MY ITVECTOR CHANGED TO BIDIRECTIONAL ITERATOR)
    class ItMap
    {

        public:

            typedef pair<const Key, T>              value_type;
            typedef value_type*                     pointer;
            typedef value_type&                     reference;
            typedef std::ptrdiff_t                  difference_type;
            typedef std::bidirectional_iterator_tag iterator_category;

            ItMap(pointer ptr = pointer()) : _ptr(ptr)                  {}
            ItMap(const ItMap<const Key, T>& x) : _ptr(x._ptr)          {}
            ItMap<pair<const Key, T> >&    operator=(const ItMap<T>& x) { this->_ptr = x._ptr; return (*this); }
            ~ItMap(void)                                                {}

            //THIS ALLOW CONVERSION FROM ITERATOR TO CONST ITERATOR
            operator ItMap<const Key, const T>() const
            {
                return (ItMap<const Key, const T>(this->_ptr));
            }

            pointer base(void) const  { return (_ptr); }
            
            reference               operator*(void) const   { return (*_ptr); }
            pointer                 operator->(void) const  { return (_ptr); }
            ItMap<const Key, T>&    operator++(void)        { _ptr = _ptr->right; return (*this); }
            ItMap<const Key, T>&    operator--(void)        { _ptr = _ptr->left; return (*this); }
            ItMap<const Key, T>     operator++(int)         { ItMap<T>   tmp(*this); _ptr = _ptr->right; return (tmp); }
            ItMap<const Key, T>     operator--(int)         { ItMap<T>   tmp(*this); _ptr = _ptr->left; return (tmp); }

        private:

            pointer _ptr;
    };

    template <class Key, class T>
    bool operator==(const ItMap<const Key, T>& x, const ItMap<const Key, T>& y)
    {
        return (x.base() == y.base());
    }

    template <class Key, class T, class U>
    bool operator==(const ItMap<const Key, T>& x, const ItVector<const Key, U>& y)
    {
        return (x.base() == y.base());
    }

    template <class Key, class T>
    bool operator!=(const ItMap<const Key, T>& x, const ItMap<const Key, T>& y)
    {
        return (x.base() != y.base());
    }

    template <class Key, class T, class U>
    bool operator!=(const ItMap<const Key, T>& x, const ItVector<const Key, U>& y)
    {
        return (x.base() != y.base());
    }

    template <class Key, class T>
    std::ostream &  operator<<(std::ostream & o, const ItMap<const Key, T>& x)
    {
        o << x.base();
        return (o);
    }
}

#endif