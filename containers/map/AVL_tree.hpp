/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:35:49 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/16 16:19:29 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

//# include "ItMap.hpp"

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

    //Helper type offering value initialization guarantee on the compare functor
    template <class Compare>
    struct key_compare
    {
        Compare comp;

        key_compare() : comp()                                  {}
        key_compare(const Compare& key_comp) : comp(key_comp)   {}
    };

    void    rotate_left(node_base* x, node_base* & root);
    void    rotate_right(node_base* x, node_base* & root);
    void    rotate_left_right(node_base* x, node_base* & root);
    void    rotate_right_left(node_base* x, node_base* & root);

    template <class Key, class Value, class KeyOfValue, class Compare, class Alloc = std::allocator<Value> >
    class AVL_tree
    {

        public:

            //TYPES
            typedef Value                                   value_type;
            typedef Compare                                 key_compare;
            typedef Alloc                                   allocator_type;
            typedef typename Alloc::reference               reference;
            typedef typename Alloc::const_reference         const_reference;
            typedef ItMap<Value>                            iterator;
            typedef ConstItMap<Value>                       const_iterator;
            typedef std::size_t                             size_type;
            typedef std::ptrdiff_t                          difference_type;
            typedef typename Allocator::pointer             pointer;
            typedef typename Allocator::const_pointer       const_pointer;
            //typedef ft::reverse_iterator<iterator>          reverse_iterator;
            //typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

    };
}

#endif