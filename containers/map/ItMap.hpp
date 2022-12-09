/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItMap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:15:50 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/09 15:23:29 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITMAP_HPP
# define ITMAP_HPP

# include "../../utils/utility.hpp"
# include "AVL_tree.hpp"

# include <cstddef>

namespace ft
{
    template <class Tp>
    struct ItMap
    {
        typedef Tp                              value_type;
        typedef Tp*                             pointer;
        typedef Tp&                             reference;
        typedef std::ptrdiff_t                  difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;

        typedef ItMap<Tp>           Self;
        typedef node_base::base_ptr base_ptr;
        typedef node<Tp>*           link_type;

        base_ptr    node;

        ItMap() : node()            {}
        ItMap(base_ptr x) : node(x) {}

        reference   operator*()     { return(*(static_cast<link_type>(node)->getDataPtr())); }
        pointer     operator->()    { return(static_cast<link_type>(node)->getDataPtr()); }

        /*Self&   operator++()
        {

        }

        Self    operator++(int)
        {

        }

        Self&   operator--()
        {

        }

        Self    operator--(int)
        {

        }*/

        friend bool operator==(const Self& x, const Self& y)    { return (x.node == y.node); }
        friend bool operator!=(const Self& x, const Self& y)    { return (x.node != y.node); }
    };
}

#endif