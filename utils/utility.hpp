/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:27:31 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/02 17:42:12 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{
    template <class Key, class T>
    struct pair
    {
        typedef Key first_type;
        typedef T   second_type;

        first_type  first;
        second_type second;
    };
}

#endif