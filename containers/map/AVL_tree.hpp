/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:35:49 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/13 15:31:08 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include <memory>

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

    template <class Key, class Value, class KeyOfValue, class Compare, class Alloc = std::allocator<Value> >
    class AVL_tree
    {

    };
}

#endif