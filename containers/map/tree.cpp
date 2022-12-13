/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:43:55 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/13 13:56:43 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVL_tree.hpp"

namespace ft
{
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
}