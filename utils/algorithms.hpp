/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:14:04 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/04 17:32:06 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_HPP
# define ALGORITHMS_HPP

namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool    equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        for (; first1 != last1; ++first1, ++first2)
        {
            if (!(*first1 == *first2))
                return (false);
        }
        return (true);
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool    equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        for (; first1 != last1; ++first1, ++first2)
        {
            if (!(pred(*first1, *first2)))
                return (false);
        }
        return (true);
    }

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        for (; first1 != last1; ++first1, ++first2)
        {
            if (first2 == last2 || *first2 < *first1)
                return (false);
            else if (*first1 < *first2)
                return (true);
        }
        return (first2 != last2);
    }

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        for (; first1 != last1; ++first1, ++first2)
        {
            if (first2 == last2 || comp(*first2, *first1))
                return (false);
            else if (comp(*first1, *first2))
                return (true);
        }
        return (first2 != last2);
    }

    template <class T>
    void    swap(T& a, T& b)
    {
        T c(a);
        
        a = b;
        b = c;
    }
}

#endif