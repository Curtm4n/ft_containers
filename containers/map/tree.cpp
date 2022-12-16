/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:43:55 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/16 15:06:14 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVL_tree.hpp"

#include <cassert>

namespace ft
{
    node_base::base_ptr node_base::minimum(base_ptr x)
    {
        while (x->left)
            x = x->left;
        return (x);
    }

    node_base::const_base_ptr   node_base::minimum(const_base_ptr x)
    {
        while (x->left)
            x = x->left;
        return (x);
    }

    node_base::base_ptr node_base::maximum(base_ptr x)
    {
        while (x->right)
            x = x->right;
        return (x);
    }
    
    node_base::const_base_ptr   node_base::maximum(const_base_ptr x)
    {
        while (x->right)
            x = x->right;
        return (x);
    }

    node_base*  node_increment(node_base* x)
    {
        if (x->right)
        {
            x = x->right;
            while (x->left)
                x = x->left;
        }
        else
        {
            node_base *y = x->parent;
            while (x == y->right)
            {
                x = y;
                y = y->parent;
            }
            if (x->right != y)
                x = y;
        }
        return (x);
    }

    const node_base*  node_increment(const node_base* x)
    {
        if (x->right)
        {
            x = x->right;
            while (x->left)
                x = x->left;
        }
        else
        {
            node_base *y = x->parent;
            while (x == y->right)
            {
                x = y;
                y = y->parent;
            }
            if (x->right != y)
                x = y;
        }
        return (x);
    }

    node_base* node_decrement(node_base* x)
    {
        if (x->parent->parent == x && x->balFactor == -2) //end() node
            x = x->right;
        else if (x->left)
        {
            x = x->left;
            while (x->right)
                x = x->right;
        }
        else
        {
            node_base *y = x->parent;
            while (x == y->left)
            {
                x = y;
                y = y->parent;
            }
            x = y;
        }
        return (x);
    }

    const node_base* node_decrement(const node_base* x)
    {
        if (x->parent->parent == x && x->balFactor == -2) //end() node
            x = x->right;
        else if (x->left)
        {
            x = x->left;
            while (x->right)
                x = x->right;
        }
        else
        {
            node_base *y = x->parent;
            while (x == y->left)
            {
                x = y;
                y = y->parent;
            }
            x = y;
        }
        return (x);
    }

    tree_header::tree_header()
    {
        header.balFactor = -2;
        reset();
    }

    void    tree_header::move_data(tree_header& from)
    {
        header.balFactor = from.header.balFactor;
        header.parent = from.header.parent;
        header.left = from.header.left;
        header.right = from.header.right;
        header.parent->parent = &header;
        node_count = from.node_count;

        from.reset();
    }

    void    tree_header::reset()
    {
        header.parent = 0;
        header.left = &header;
        header.right = &header;
        node_count = 0;
    }

    /*        LEFT ROTATION
    *       /                /
    *      x                y
    *     / \              / \
    *    a   y      =>    x   c
    *       / \          / \
    *     [b]   c       a  [b]
    */
    void    rotate_left(node_base* x, node_base* & root)
    {
        assert(x->right); //abort called if x->right is NULL (this function should never be called)
        
        node_base* y = x->right;

        //change the child
        x->right = y->left;
        y->left = x;

        //change the parent
        y->parent = x->parent;
        x->parent = y;

        if (x->right) //this is b
            x->right->parent = x;

        //change the parent's child if it exist or change the root
        if (x == root)
            root = y;
        else if (y->parent->right == x)
            y->parent->right = y;
        else
            y->parent->left = y;

        if (y->balFactor == 1)
        {
            /*
            *       /                /
            *      x                y
            *     / \              / \
            *    a   y      =>    x   c
            *       / \          / \ /
            *      b   c        a  b d
            *         /
            *        d
            */
           y->balFactor = 0;
           x->balFactor = 0;
        }
        else
        {
            /*
            *       /                /
            *      x                y
            *     / \              / \
            *    a   y      =>    x   c
            *       / \          / \
            *      b   c        a   b
            *       \               \
            *        d               d
            */
           y->balFactor = -1;
           x->balFactor = 1;
        }
    }

    /*       RIGHT ROTATION
    *      /                /
    *     x                y
    *    / \      =>      / \
    *   y   a            c   x
    *  / \              / \
    * c  [b]          [b]  a
    */
    void    rotate_right(node_base* x, node_base* & root)
    {
        assert(x->left); //abort called if x->left is NULL (this function should never be called)

        node_base* y = x->left;

        //change the child
        x->left = y->right;
        y->right = x;

        //change the parent
        y->parent = x->parent;
        x->parent = y;

        if (x->left) //this is b
            x->left->parent;

        //change the parent's child if it exist or change the root
        if (x == root)
            root = y;
        else if (y->parent->right == x)
            y->parent->right = y;
        else
            y->parent->left = y;

        if (y->balFactor == -1)
        {
            y->balFactor = 0;
            x->balFactor = 0;
        }
        else
        {
            y->balFactor = 1;
            x->balFactor = -1;
        }
    }

    /*            LEFT_RIGHT ROTATION
    *          /                      /
    *         a                      c
    *        / \                    / \
    *       b   g      =>          /   \
    *      / \                    b    a
    *     d   c                  / \  / \
    *        / \                d  e  f  g
    *       e   f
    */
    void    rotate_left_right(node_base* a, node_base* & root)
    {
        assert(a->left && a->left->right);

        node_base* b = a->left;
        node_base* c = b->right;

        // a and b link to c' sons
        a->left = c->right;
        b->right = c->left;

        // c becomes the parent of a and b
        c->right = a;
        c->left = b;

        // c links to the parent of a and b
        c->parent = a->parent;
        a->parent = c;
        b->parent = c;

        // check c' sons and link to their new parent
        if (a->left) // this is f
            a->left->parent = a;
        if (b->right) // this is e
            b->right->parent = b;

        // the parent of a and b link to c
        if (a == root)
            root = c;
        else if (c->parent->left == a)
            c->parent->left = c;
        else
            c->parent->right = c;

        switch (c->balFactor)
        {
            case -1:
                /*
                *    c
                *   /
                *  e
                */
               a->balFactor = 1;
               b->balFactor = 0;
               break ;
            case 0:
                a->balFactor = 0;
                b->balFactor = 0;
                break ;
            case 1:
                /*
                *    c
                *     \
                *      f
                */
               a->balFactor = 0;
               b->balFactor = -1;
               break ;
            default:
                assert(false);
        }
        c->balFactor = 0;
    }

    /*          RIGHT_LEFT ROTATION
    *       /                       /
    *       a                       c
    *      / \                     / \
    *     d   b      =>           /   \
    *        / \                 a     b
    *       c   g               / \   / \
    *      / \                 d   e  f  g
    *     e   f
    */
    void    rotate_right_left(node_base* a, node_base* & root)
    {
        assert(a->right && a->right->left);

        node_base* b = a->right;
        node_base* c = b->left;

        // a and b link to c' sons
        a->right = c->left;
        b->left = c->right;

        // c becomes the parent of a and b
        c->left = a;
        c->right = b;

        // c links to the parent of a and b
        c->parent = a->parent;
        a->parent = c;
        b->parent = c;

        // check c' sons and link to their new parent
        if (a->right) // this is e
            a->right->parent = a;
        if (b->left) // this is f
            b->left->parent = b;

        // the parent of a and b link to c
        if (a == root)
            root = c;
        else if (c->parent->left == a)
            c->parent->left = c;
        else
            c->parent->right = c;

        switch (c->balFactor)
        {
            case -1:
                /*
                *    c
                *   /
                *  e
                */
               a->balFactor = 0;
               b->balFactor = 1;
               break ;
            case 0:
                a->balFactor = 0;
                b->balFactor = 0;
                break ;
            case 1:
                /*
                *   c
                *    \
                *     f
                */
               a->balFactor = -1;
               b->balFactor = 0;
               break ;
            default:
                assert(false);
        }
        c->balFactor = 0;
    }
}