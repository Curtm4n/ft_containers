/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:36:57 by cdapurif          #+#    #+#             */
/*   Updated: 2022/11/15 21:14:49 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
    template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator
    {
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
    };

    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };

    template <class T>
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t                     difference_type;
        typedef T                                  value_type;
        typedef T*                                 pointer;
        typedef T&                                 reference;
        typedef std::random_access_iterator_tag    iterator_category;
    };

    template <class T>
    struct iterator_traits<const T*>
    {
        typedef std::ptrdiff_t                     difference_type;
        typedef T                                  value_type;
        typedef const T*                           pointer;
        typedef const T&                           reference;
        typedef std::random_access_iterator_tag    iterator_category;
    };

    template <class Iterator>
    class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
                                            typename iterator_traits<Iterator>::value_type,
                                            typename iterator_traits<Iterator>::difference_type,
                                            typename iterator_traits<Iterator>::pointer,
                                            typename iterator_traits<Iterator>::reference>
    {
        
        protected:

            Iterator    current;
        
        public:

            typedef Iterator                                                iterator_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::reference           reference;
            typedef typename iterator_traits<Iterator>::pointer             pointer;

            reverse_iterator() : current(iterator_type())                                       {}
            explicit reverse_iterator(iterator_type it) : current(it)                           {}
            template <class Iter>
                reverse_iterator(const reverse_iterator<Iter>& rev_it) : current(rev_it.base()) {}

            iterator_type   base() const    { return (current); }

            reference   operator*() const                           { iterator_type tmp(current); return (*--tmp); }
            pointer     operator->() const                          { return (&(operator*())); }
            reverse_iterator&   operator++()                        { --current; return (*this); }
            reverse_iterator    operator++(int)                     { reverse_iterator  tmp(*this); --current; return (tmp); }
            reverse_iterator&   operator--()                        { ++current; return (*this); }
            reverse_iterator    operator--(int)                     { reverse_iterator  tmp(*this); ++current; return (tmp); }
            reverse_iterator    operator+(difference_type n) const  { return (reverse_iterator(current - n)); }
            reverse_iterator&   operator+=(difference_type n)       { current -= n; return (*this); }
            reverse_iterator    operator-(difference_type n) const  { return (reverse_iterator(current + n)); }
            reverse_iterator&   operator-=(difference_type n)       { current += n; return (*this); }
            reference           operator[](difference_type n) const { return (current[-n - 1]); }
    };

    template <class Iterator>
    bool    operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {
        return (x.base() == y.base());
    }

    template <class T, class U>
    bool    operator==(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
    {
        return (x.base() == y.base());
    }

    template <class Iterator>
    bool    operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {
        return (x.base() != y.base());
    }

    template <class T, class U>
    bool    operator!=(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
    {
        return (x.base() != y.base());
    }

    template <class Iterator>
    bool    operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {
        return (x.base() < y.base());
    }

    template <class T, class U>
    bool    operator>(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
    {
        return (x.base() < y.base());
    }

    template <class Iterator>
    bool    operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {
        return (x.base() <= y.base());
    }

    template <class T, class U>
    bool    operator>=(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
    {
        return (x.base() <= y.base());
    }

    template <class Iterator>
    bool    operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {
        return (x.base() > y.base());
    }

    template <class T, class U>
    bool    operator<(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
    {
        return (x.base() > y.base());
    }

    template <class Iterator>
    bool    operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {
        return (x.base() >= y.base());
    }

    template <class T, class U>
    bool    operator<=(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
    {
        return (x.base() >= y.base());
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type    operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {
        return (y.base() - x.base());
    }

    template <class T, class U>
    typename reverse_iterator<T>::difference_type    operator-(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
    {
        return (y.base() - x.base());
    }

    template <class Iterator>
    reverse_iterator<Iterator>  operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
    {
        return (x + n);
    }
}

#endif