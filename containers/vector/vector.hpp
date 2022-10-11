/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:27:03 by cdapurif          #+#    #+#             */
/*   Updated: 2022/10/11 17:21:09 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <iterator>
# include <cstddef>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        
        public:

            //TYPES
            typedef typename Allocator::reference           reference;
            typedef typename Allocator::const_reference     const_reference;
            //typedef NEED IMPLEMENTATION                   iterator;
            //typedef NEED IMPLEMENTATION                   const_iterator;
            typedef std::size_t                             size_type;
            typedef std::ptrdiff_t                          difference_type;
            typedef T                                       value_type;
            typedef Allocator                               allocator_type;
            typedef typename Allocator::pointer             pointer;
            typedef typename Allocator::const_pointer       const_pointer;
            //typedef std::reverse_iterator<iterator>       reverse_iterator;
            //typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

            //CONSTRUCTORS/COPY/DESTRUCTORS
            explicit    vector(const Allocator& = Allocator()); //Default constructor
            explicit    vector(size_type n, const T& value = T(), const Allocator& = Allocator()); //Parametric constructor
            template <class InputIterator>
                vector(InputIterator first, InputIterator last, const Allocator& = Allocator()); //Range Constructor
            vector(const vector<T, Allocator>& x); //Copy constructor
            ~vector(); //Destructor
            vector<T, Allocator>&   operator=(const vector<T, Allocator>& x); //Assignation operator
            template <class InputIterator>
                void    assign(InputIterator first, InputIterator last);
            void    assign(size_type n, const T& u);
            allocator_type  get_allocator() const;

            //ITERATORS
            //iterator                  begin();
            //const_iterator            begin() const;
            //iterator                  end();
            //const_iterator            end() const;
            //reverse_iterator          rbegin();
            //const_reverse_iterator    rbegin() const;
            //reverse_iterator          rend();
            //const_reverse_iterator    rend() const;

            //CAPACITY
            size_type   size() const;
            size_type   max_size() const;
            void        resize(size_type sz, T c = T());
            size_type   capacity() const;
            bool        empty() const;
            void        reserve(size_type n);

            //ELEMENT ACCESS
            reference       operator[](size_type n);
            const_reference operator[](size_type n) const;
            const_reference at(size_type n) const;
            reference       at(size_type n);
            reference       front();
            const_reference front() const;
            reference       back();
            const_reference back() const;

            //MODIFIERS
            void        push_back(const T& x);
            void        pop_back();
            //iterator  insert(iterator position, const T& x);
            //void      insert(iterator position, size_type n, const T& x);
            //template <class InputIterator>
                //void    insert(iterator position, InputIterator first, InputIterator last);
            //iterator  erase(iterator position);
            //iterator  erase(iterator first, iterator last);
            void        swap(vector<T, Allocator>&);
            void        clear();

        private:

            value_type      *_array;
            size_type       _size;
            size_type       _capacity;
            allocator_type  _alloc;
    };

//CONSTRUCTORS

    template <class T, class Allocator>
    vector<T, Allocator>::vector(const Allocator& alloc) : _size(0), _capacity(0), _alloc(alloc)
    {
        _array = _alloc.allocate(_capacity);
    }

    template <class T, class Allocator>
    vector<T, Allocator>::vector(size_type n, const T& value, const Allocator& alloc) : _size(n), _capacity(n), _alloc(alloc)
    {
        _array = _alloc.allocate(_capacity);
        for (size_type i = 0; i < n; i++)
            _alloc.construct(_array + i, value);
    }

//DESTRUCTOR

    template <class T, class Allocator>
    vector<T,Allocator>::~vector()
    {
        _alloc.deallocate(_array, _capacity);
    }

//CAPACITY

    template <class T, class Allocator>
    typename vector<T, Allocator>::size_type   vector<T, Allocator>::size() const
    {
        return (_size);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::size_type   vector<T, Allocator>::capacity() const
    {
        return (_capacity);
    }

//OPERATORS

    template <class T, class Allocator>
        bool    operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

    template <class T, class Allocator>
        bool    operator< (const vector<T, Allocator>& x, const vector<T, Allocator>& y);

    template <class T, class Allocator>
        bool    operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

    template <class T, class Allocator>
        bool    operator> (const vector<T, Allocator>& x, const vector<T, Allocator>& y);

    template <class T, class Allocator>
        bool    operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

    template <class T, class Allocator>
        bool    operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

//SPECIALIZED ALGORITHMS

    template <class T, class Allocator>
        void    swap(vector<T, Allocator>& x, vector<T, Allocator>& y);
}

#endif