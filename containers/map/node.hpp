/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:27:41 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/19 16:30:51 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <cstddef>

namespace ft
{
    struct node_base
    {
        typedef node_base*          base_ptr;
        typedef const node_base*    const_base_ptr;

        base_ptr    parent;
        base_ptr    left;
        base_ptr    right;
        signed char balFactor;

        static base_ptr         minimum(base_ptr x);
        static const_base_ptr   minimum(const_base_ptr x);
        static base_ptr         maximum(base_ptr x);
        static const_base_ptr   maximum(const_base_ptr x);
    };

    template <class Tp>
    struct node : public node_base
    {
        typedef node<Tp>*   link_type;

        Tp  data;

        node(const Tp& val) : data(val) {}

        Tp*         getDataPtr()        { return (&data); }
        const Tp*   getDataPtr() const  { return (&data); }
    };

    struct tree_header
    {
        node_base   header;
        std::size_t node_count;

        tree_header();

        void    move_data(tree_header& from);
        void    reset();
    };
}

#endif