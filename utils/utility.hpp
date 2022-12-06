/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:27:31 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/06 17:14:01 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

# include <algorithm>

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        typedef T1  first_type;
        typedef T2  second_type;

        first_type  first;
        second_type second;

        pair() : first(), second()                                          {}
        pair(const T1& x, const T2& y) : first(x), second(y)                {}
        template<class U, class V>
            pair(const pair<U, V>& p) : first(p.first), second(p.second)    {}
        
        pair&   operator=(const pair& pr)
        {
            if (this != &pr)
            {
                first = pr.first;
                second = pr.second;
            }
            return (*this);
        }
        
        ~pair() {}

        void    swap(pair& pr)
        {
            std::swap(first, pr.first);
            std::swap(second, pr.second);
        }
    };

    template <class T1, class T2>
    bool    operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool    operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T1, class T2>
    bool    operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool    operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return (!(rhs < lhs));
    }
    
    template <class T1, class T2>
    bool    operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return (rhs < lhs);
    }
    
    template <class T1, class T2>
    bool    operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T1, class T2>
    void    swap(pair<T1, T2>& x, pair<T1, T2>& y)
    {
        x.swap(y);
    }

    template <class T1, class T2>
    pair<T1, T2>    make_pair (T1 x, T2 y)
    {
        return (pair<T1, T2>(x, y));
    }
}

#endif