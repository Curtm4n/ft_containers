/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:09:27 by cdapurif          #+#    #+#             */
/*   Updated: 2022/09/21 18:22:23 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
    struct true_type {};
    struct false_type {};
    
    template<class T>
        struct is_integral {};
    
    template<>
        struct is_integral<unsigned char> : public true_type {};
    template<>
        struct is_integral<unsigned short> : public true_type{};
    template<>
        struct is_integral<unsigned int> : public true_type{};
    template<>
        struct is_integral<unsigned long> : public true_type{};
    template<>
        struct is_integral<signed char> : public true_type{};
    template<>
        struct is_integral<short> : public true_type{};
    template<>
        struct is_integral<int> : public true_type{};
    template<>
        struct is_integral<long> : public true_type{};
    template<>
        struct is_integral<char> : public true_type{};
    template<>
        struct is_integral<bool> : public true_type{};
}

#endif