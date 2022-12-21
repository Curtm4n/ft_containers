/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:35:49 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/21 19:11:44 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include "node.hpp"
# include "ItMap.hpp"
# include "../../utils/iterator.hpp"

# include <memory>
# include <cstddef>
# include <functional>

namespace ft
{
    //Helper type offering value initialization guarantee on the compare functor
    template <class Compare>
    struct avl_key_compare
    {
        Compare comp;

        avl_key_compare() : comp()                                  {}
        avl_key_compare(const Compare& key_comp) : comp(key_comp)   {}
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
            typedef typename Alloc::pointer                 pointer;
            typedef typename Alloc::const_pointer           const_pointer;
            typedef ft::reverse_iterator<iterator>          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

        private:

            typedef node_base*          base_ptr;
            typedef const node_base*    const_base_ptr;

            typedef node<Value>*        link_type;
            typedef const node<Value>*  const_link_type;

            //MAKE A NODE_ALLOCATOR TYPE FOR ALLOCATING NODES INSTEAD OF JUST PAIRS
            typedef typename Alloc::template rebind<node<Value> >::other   node_allocator;

            //INNER STRUCT THAT CONTAIN HEADER NODE AND KEY_COMPARE
            template <class _Compare>
            struct avl_impl : public avl_key_compare<_Compare>, public tree_header
            {
                avl_impl()                                                                  {}
                avl_impl(const _Compare& key_comp) : avl_key_compare<_Compare>(key_comp)    {}

                ~avl_impl() {}
            };

            //THE ATTRIBUTES OF MY AVL_TREE CLASS
            avl_impl<Compare>   M_impl;

            node_allocator      M_alloc;

        private:

            base_ptr&       M_root()            { return (M_impl.header.parent); }
            const_base_ptr  M_root() const      { return (M_impl.header.parent); }

            base_ptr&       M_leftmost()        { return (M_impl.header.left); }
            const_base_ptr  M_leftmost() const  { return (M_impl.header.left); }

            base_ptr&       M_rightmost()       { return (M_impl.header.right); }
            const_base_ptr  M_rightmost() const { return (M_impl.header.right); }

            link_type       M_begin()       { return (static_cast<link_type>(M_impl.header.parent)); }
            const_link_type M_begin() const { return (static_cast<const_link_type>(M_impl.header.parent)); }

            base_ptr        M_end()         { return (&M_impl.header); }
            const_base_ptr  M_end() const   { return (&M_impl.header); }

            static const Key&   S_key(const_link_type x)    { return (KeyOfValue()(*(x->getDataPtr()))); }
            static const Key&   S_key(const_base_ptr x)     { return (S_key(static_cast<const_link_type>(x))); }

            static link_type        S_left(base_ptr x)          { return (static_cast<link_type>(x->left)); }
            static const_link_type  S_left(const_base_ptr x)    { return (static_cast<const_link_type>(x->left)); }

            static link_type        S_right(base_ptr x)         { return (static_cast<link_type>(x->right)); }
            static const_link_type  S_right(const_base_ptr x)   { return (static_cast<const_link_type>(x->right)); }

            static base_ptr         S_minimum(base_ptr x)       { return (node_base::minimum(x)); }
            static const_base_ptr   S_minimum(const_base_ptr x) { return (node_base::minimum(x)); }

            static base_ptr         S_maximum(base_ptr x)       { return (node_base::maximum(x)); }
            static const_base_ptr   S_maximum(const_base_ptr x) { return (node_base::maximum(x)); }

        public:

            AVL_tree()                                                                                                      {}
            AVL_tree(const Compare& comp, const allocator_type& alloc = allocator_type()) : M_impl(comp), M_alloc(alloc)    {}

            ~AVL_tree() {}

    };
}

#endif