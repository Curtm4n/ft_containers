/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:18:40 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/04 17:47:40 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "AVL_tree.hpp"
# include "../../utils/utility.hpp"
# include "../../utils/algorithms.hpp"

# include <memory>
# include <cstddef>
# include <functional>

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
    class map
    {
        
        public:

            //TYPES
            typedef Key                                     key_type;
            typedef T                                       mapped_type;
            typedef pair<const Key, T>                      value_type;
            typedef Compare                                 key_compare;
            typedef Allocator                               allocator_type;
            typedef typename Allocator::reference           reference;
            typedef typename Allocator::const_reference     const_reference;
            typedef std::size_t                             size_type;
            typedef std::ptrdiff_t                          difference_type;
            typedef typename Allocator::pointer             pointer;
            typedef typename Allocator::const_pointer       const_pointer;

            //COMPARISON CLASS
            class value_compare : public std::binary_function<value_type,value_type,bool>
            {
                
                friend class map;
                
                protected:
                
                    Compare comp;

                    value_compare(Compare c) : comp(c) {}
                
                public:

                    bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
            };

        private:

            typedef AVL_tree<key_type, value_type, std::_Select1st<value_type>, key_compare, allocator_type>    avl_tree;

            //The actual tree structure
            avl_tree    tree;

        public:

            //TYPES
            typedef typename avl_tree::iterator             iterator;
            typedef typename avl_tree::const_iterator       const_iterator;
            typedef ft::reverse_iterator<iterator>          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;


            //CONSTRUCTORS
            explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : tree(comp, alloc) {}                              //Default Constructor       //DONE

            template <class InputIterator>
            map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : tree(comp, alloc) //Range Constructor         //DONE
            {
                insert(first, last);
            }

            map(const map<Key,T,Compare,Allocator>& x) : tree(x.tree)   {}                                                                          //Copy Constructor          //DONE

            map<Key,T,Compare,Allocator>&   operator=(const map<Key,T,Compare,Allocator>& x)                                                        //Assignement operator      //DONE
            {
                if (this != &x)
                {
                    this->tree = x.tree;
                }
                return (*this);
            }

            //DESTRUCTOR
            ~map()  {}  //DONE

            //ITERATORS
            iterator                begin()         { return (tree.begin()); }  //DONE
            const_iterator          begin() const   { return (tree.begin()); }  //DONE
            iterator                end()           { return (tree.end()); }    //DONE
            const_iterator          end() const     { return (tree.end()); }    //DONE
            reverse_iterator        rbegin()        { return (tree.rbegin()); } //DONE
            const_reverse_iterator  rbegin() const  { return (tree.rbegin()); } //DONE
            reverse_iterator        rend()          { return (tree.rend()); }   //DONE
            const_reverse_iterator  rend() const    { return (tree.rend()); }   //DONE

            //CAPACITY
            bool        empty() const       { return (tree.empty()); }      //DONE
            size_type   size() const        { return (tree.size()); }       //DONE
            size_type   max_size() const    { return (tree.max_size()); }   //DONE

            allocator_type  get_allocator() const   { return (tree.get_allocator()); }  //DONE

            //ELEMENT ACCESS
            T&  operator[](const key_type& x)   { return ((*((insert(ft::make_pair(x, T()))).first)).second); } //DONE

            //MODIFIERS
            pair<iterator, bool>    insert(const value_type& x)                     { return (tree.insert(x)); }            //DONE
            iterator                insert(iterator position, const value_type& x)  { return (tree.insert(position, x)); }  //DONE
            template <class InputIterator>
                void                insert(InputIterator first, InputIterator last) { tree.insert(first, last); }           //DONE
            void                    erase(iterator position)                        { tree.erase(position); }               //DONE
            size_type               erase(const key_type& x)                        { return (tree.erase_key(x)); }         //DONE
            void                    erase(iterator first, iterator last)            { tree.erase(first, last); }            //DONE
            void                    swap(map<Key,T,Compare,Allocator>& x)           { tree.swap(x.tree); }                  //DONE
            void                    clear()                                         { tree.clear(); }                       //DONE

            //OBSERVERS
            key_compare     key_comp() const    { return (tree.key_comp()); }   //DONE
            value_compare   value_comp() const  { return (tree.key_comp()); }   //DONE

            //MAP OPERATIONS
            iterator                            find(const key_type& x)                 { return (tree.find(x)); }                          //DONE
            const_iterator                      find(const key_type& x) const           { return (tree.find(x)); }                          //DONE
            size_type                           count(const key_type& x) const          { return (tree.find(x) != tree.end() ? 1 : 0); }    //DONE
            iterator                            lower_bound(const key_type& x)          { return (tree.lower_bound(x)); }                   //DONE
            const_iterator                      lower_bound(const key_type& x) const    { return (tree.lower_bound(x)); }                   //DONE
            iterator                            upper_bound(const key_type& x)          { return (tree.upper_bound(x)); }                   //DONE
            const_iterator                      upper_bound(const key_type& x) const    { return (tree.upper_bound(x)); }                   //DONE
            pair<iterator,iterator>             equal_range(const key_type& x)          { return (tree.equal_range(x)); }                   //DONE
            pair<const_iterator,const_iterator> equal_range(const key_type& x) const    { return (tree.equal_range(x)); }                   //DONE

            //NON MEMBERS OPERATOR OVERLOADS
            template <class K1, class T1, class C1, class A1>
            friend bool operator==(const map<K1, T1, C1, A1>&, const map<K1, T1, C1, A1>&);     //DONE

            template <class K1, class T1, class C1, class A1>
            friend bool operator<(const map<K1, T1, C1, A1>&, const map<K1, T1, C1, A1>&);      //DONE

            template <class K1, class T1, class C1, class A1>
            friend bool operator!=(const map<K1, T1, C1, A1>&, const map<K1, T1, C1, A1>&);     //DONE

            template <class K1, class T1, class C1, class A1>
            friend bool operator>(const map<K1, T1, C1, A1>&, const map<K1, T1, C1, A1>&);      //DONE

            template <class K1, class T1, class C1, class A1>
            friend bool operator>=(const map<K1, T1, C1, A1>&, const map<K1, T1, C1, A1>&);     //DONE

            template <class K1, class T1, class C1, class A1>
            friend bool operator<=(const map<K1, T1, C1, A1>&, const map<K1, T1, C1, A1>&);     //DONE
    };

    //RELATIONAL OPERATORS
    template <class Key, class T, class Compare, class Allocator>
    bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)   { return(x.tree == y.tree); }

    template <class Key, class T, class Compare, class Allocator>
    bool operator< (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)   { return(x.tree < y.tree); }

    template <class Key, class T, class Compare, class Allocator>
    bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)   { return(x.tree != y.tree); }

    template <class Key, class T, class Compare, class Allocator>
    bool operator> (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)   { return(x.tree > y.tree); }

    template <class Key, class T, class Compare, class Allocator>
    bool operator>=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)   { return(x.tree >= y.tree); }

    template <class Key, class T, class Compare, class Allocator>
    bool operator<=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)   { return(x.tree <= y.tree); }

    //SPECIALIZED ALGORITHM:
    template <class Key, class T, class Compare, class Allocator>
    void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y)
    {
        x.swap(y);
    }
}

#endif