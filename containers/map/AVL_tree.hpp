/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:35:49 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/23 17:34:48 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include "node.hpp"
# include "ItMap.hpp"
# include "../../utils/iterator.hpp"

# include <memory>
# include <cstddef>
# include <cassert>
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

            
            // [x] is the new node to insert
            // [p] is the parent of [x]
            void    insert_and_rebalance(bool insertLeft, base_ptr x, base_ptr p)
            {
                // construct the new node to insert
                x->parent = p;
                x->left = 0;
                x->right = 0;
                x->balFactor = 0;

                if (insertLeft)
                {
                    p->left = x;
                    if (p == &M_impl.header) // if p is header (x is root)
                    {
                        M_impl.header.parent = x;
                        M_impl.header.right = x;
                    }
                    else if (p == M_impl.header.left) // if p is son of header (leftmost node)
                        M_impl.header.left = x;
                }
                else
                {
                    p->right = x;
                    if (p == M_impl.header.right)
                        M_impl.header.right = x;
                }

                // rebalance
                while (x != M_root())
                {
                    switch (x->parent->balFactor)
                    {
                        case 0:
                            // same size right and left subtree of x parent
                            // one of them will become taller after inserting the node
                            x->parent->balFactor = (x == x->parent->left) ? -1 : 1;
                            x = x->parent; // percolate up the path
                            break ;
                        
                        case 1:
                            // right subtree is taller
                            if (x == x->parent->left) // if inserted node to the left
                                x->parent->balFactor = 0;
                            else
                            {
                                // if inserted node in the right, become more taller probably
                                // for shortening it, we need to rotate it
                                if (x->balFactor == -1) // x have a taller left, do a right_left rotation to shorten the left
                                    rotate_right_left(x->parent, M_root());
                                else // just do a left rotation to shorten the right
                                    rotate_left(x->parent, M_root());
                            }
                            // adjust once is enough
                            return ;

                        case -1:
                            // -1 mean that x parent have a taller left subtree
                            if (x == x->parent->left)
                            {
                                // if inserted node to the left, become more taller probably
                                // for shortening it, we need to rotate it
                                if (x->balFactor == 1) // x have a taller right, do a left_right rotation to shortening the right
                                    rotate_left_right(x->parent, M_root());
                                else // just do a right rotation to shorten the left
                                    rotate_right(x->parent, M_root());
                            }
                            else
                                x->parent->balFactor = 0;
                            
                            // adjust once is enough
                            return ;

                        default:
                            assert(false);
                    }
                }
            }

            pair<iterator, bool>    insert_unique(const Value& v)
            {
                base_ptr    x = M_begin();
                base_ptr    y = M_end();
                bool        comp = true;

                while (x)
                {
                    y = x;
                    comp = M_impl.comp(KeyOfValue()(v), S_key(x));
                    x = comp ? S_left(x) : S_right(x);
                }
                iterator j = iterator(y);
                if (comp) // left (v < parent node)
                {
                    if (j == iterator(M_impl.header.left)) // leftmost
                        return (pair<iterator, bool>(M_insert(x, y, v), true));
                    else
                        --j;
                }
                if (M_impl.comp(S_key(j.node), KeyOfValue()(v)))
                    return (pair<iterator, bool>(M_insert(x, y, v), true));
                return (pair<iterator, bool>(j, false));
            }

            // [x] is the child of [p],
            // [x] is always null passed from insert_unique, no need to consider in theory
            // [p] is the parent of [x]
            iterator    M_insert(base_ptr x, base_ptr p, const Value& v)
            {
                bool insertLeft = (x || p == M_end() || M_impl.comp(KeyOfValue()(v), S_key(p)));

                base_ptr z = create_node(v);
                insert_and_rebalance(insertLeft, z, p);
                ++M_impl.node_count;
                return (iterator(z));
            }

            link_type   create_node(const Value& v)
            {
                link_type   z;

                z = M_alloc.allocate(1);
                M_alloc.construct(z, v);

                return (z);
            }

            // erase node [z] and return the deleted node
            base_ptr    erase_and_rebalance(base_ptr z)
            {
                base_ptr    y = z;
                base_ptr    x = 0;
                base_ptr    xParent = 0;

                // x is the child of y
                if (!y->left)
                    x = y->right;
                else if (!y->right)
                    x = y->left;
                else
                {
                    // y has two children
                    // find the successor
                    y = y->right;
                    while (y->left)
                        y = y->left;
                    x = y->right; // y has no left child, so x is the successor 
                }

                if (y != z) // z has two children
                {
                    // we make the successor y to replace z
                    // z will disconnect to its children and y link to them
                    z->left->parent = y;
                    y->left = z->left;
                    if (y != z->right)
                    {
                        // y will be moved, need to link its child to its parent
                        xParent = y->parent;
                        if (x)
                            x->parent = y->parent;
                        y->parent->left = x;
                        y->right = z->right;
                        z->right->parent = y;
                    }
                    else // y == z->right, mean y has no left child and x is the right of y
                        xParent = y;

                    // link z parent to y
                    if (M_root() == z)
                        M_root() = y;
                    else if (z->parent->left == z)
                        z->parent->left = y;
                    else
                        z->parent->right = y;
                    y->parent = z->parent;
                    y->balFactor = z->balFactor;
                }
                else // mean that z has one child or none and y == z
                {
                    // x become the successor
                    xParent = y->parent;
                    if (x)
                        x->parent = y->parent;
                    if (M_root() == z)
                        M_root() = x;
                    else if (z->parent->left == z)
                        z->parent->left = x;
                    else
                        z->parent->right = x;
                    if (M_leftmost() == z)
                    {
                        if (!z->right)
                            M_leftmost() = z->parent;
                        else
                            M_leftmost() = node_base::minimum(x);
                    }
                    if (M_rightmost() == z)
                    {
                        if (!z->left)
                            M_rightmost() = z->parent;
                        else
                            M_rightmost() = node_base::maximum(x);
                    }
                }

                // rebalance
                while (x != M_root())
                {
                    switch (xParent->balFactor)
                    {
                        case 0:
                            xParent->balFactor = (x == xParent->right) ? -1 : 1;
                            return (z);
                        case -1:
                            //left subtree taller
                            if (x == xParent->left) // erase the node in the left, balance just right
                            {
                                xParent->balFactor = 0;
                                x = xParent;
                                xParent = xParent->parent;
                            }
                            else // erase the node in the right, need to shorten the left
                            {
                                base_ptr a = xParent->left;
                                if (a->balFactor == 1) // check whether need a double rotation
                                    rotate_left_right(a, M_root());
                                else
                                    rotate_right(xParent, M_root());
                                x = xParent->parent;
                                xParent = xParent->parent->parent;
                                if (x->balFactor == 1)
                                    return (z);
                            }
                            break ;
                        case 1:
                            // right subtree taller
                            if (x == xParent->right) // erase the node in the right, balance just right
                            {
                                xParent->balFactor = 0;
                                x = xParent;
                                xParent = xParent->parent;
                            }
                            else
                            {
                                base_ptr a = xParent->right;
                                if (a->balFactor == -1) // check whether need a double rotation
                                    rotate_right_left(a, M_root());
                                else
                                    rotate_left(xParent, M_root());
                                x = xParent->parent;
                                xParent = xParent->parent->parent;
                                if (x->balFactor == -1)
                                    return (z);
                            }
                            break ;
                        default:
                            assert(false);
                    }
                }
                return (z);
            }

            void    M_erase(link_type x) // erase recursively (all the children of x and their children etc...) without rebalancing
            {
                while (x)
                {
                    M_erase(S_right(x));
                    link_type y = S_left(x);
                    M_drop_node(x);
                    x = y;
                }
            }

            void    M_drop_node(link_type x)
            {
                M_alloc.destroy(x);
                M_alloc.deallocate(x, 1);
            }

        public:

            AVL_tree()                                                                                                      {}
            AVL_tree(const Compare& comp, const allocator_type& alloc = allocator_type()) : M_impl(comp), M_alloc(alloc)    {}
            AVL_tree(const AVL_tree& x);
            AVL_tree&   operator=(const AVL_tree& x);

            ~AVL_tree() { M_erase(M_begin()); }

    };
}

#endif