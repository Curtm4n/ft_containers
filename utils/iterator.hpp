/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:36:57 by cdapurif          #+#    #+#             */
/*   Updated: 2022/11/15 13:35:14 by cdapurif         ###   ########.fr       */
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
    class reverse_iterator
    {
        
        public:

            typedef Iterator                                                iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iterator>::value_type          value_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::pointer             pointer;
            typedef typename iterator_traits<Iterator>::reference           reference;

        private:

            iterator_type   _it;

        public:

            reverse_iterator() : _it(iterator_type())                                       {}
            explicit reverse_iterator(iterator_type it) : _it(it)                           {}
            template <class Iter>
                reverse_iterator(const reverse_iterator<Iter>& rev_it) : _it(rev_it._it)    {}  //TO CHECK

            iterator_type   base() const    { return (_it); }
    };
}

#endif