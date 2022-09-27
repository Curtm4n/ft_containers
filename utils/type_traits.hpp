/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:09:27 by cdapurif          #+#    #+#             */
/*   Updated: 2022/09/27 16:37:36 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
    template <class T, T v>
        struct integral_constant
        {
            static const T                  value = v;
            typedef T                       value_type;
            typedef integral_constant<T,v>  type;
            operator T()                    { return v; }
        };

    typedef integral_constant<bool,true>    true_type;
    typedef integral_constant<bool,false>   false_type;
    
    template<class T>   struct is_integral                          : public false_type {};
    
    template<>          struct is_integral<unsigned char>           : public true_type {};
    template<>          struct is_integral<unsigned short int>      : public true_type {};
    template<>          struct is_integral<unsigned int>            : public true_type {};
    template<>          struct is_integral<unsigned long int>       : public true_type {};
    template<>          struct is_integral<unsigned long long int>  : public true_type {};
    template<>          struct is_integral<signed char>             : public true_type {};
    template<>          struct is_integral<short int>               : public true_type {};
    template<>          struct is_integral<int>                     : public true_type {};
    template<>          struct is_integral<long int>                : public true_type {};
    template<>          struct is_integral<long long int>           : public true_type {};
    template<>          struct is_integral<char>                    : public true_type {};
    template<>          struct is_integral<wchar_t>                 : public true_type {};
    template<>          struct is_integral<bool>                    : public true_type {};


    template<bool B, class T = void>
        struct enable_if {};
 
    template<class T>
        struct enable_if<true, T> { typedef T type; };
}

#endif