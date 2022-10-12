/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:27:03 by cdapurif          #+#    #+#             */
/*   Updated: 2022/10/12 21:51:50 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <iterator>
# include <cstddef>
# include <stdexcept>

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

            //CONSTRUCTORS
            explicit    vector(const Allocator& = Allocator());                                     //Default constructor       //DONE
            explicit    vector(size_type n, const T& value = T(), const Allocator& = Allocator());  //Parametric constructor    //DONE
            template <class InputIterator>
                vector(InputIterator first, InputIterator last, const Allocator& = Allocator());    //Range Constructor
            vector(const vector<T, Allocator>& x);                                                  //Copy constructor          //DONE
            vector<T, Allocator>&   operator=(const vector<T, Allocator>& x);                       //Assignation operator      //TO FINISH (maybe require accessors)

            //DESTRUCTOR
            ~vector();

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
            size_type   size() const;                       //DONE
            size_type   max_size() const;                   //DONE
            void        resize(size_type sz, T c = T());
            size_type   capacity() const;                   //DONE
            bool        empty() const;                      //DONE
            void        reserve(size_type n);

            //ELEMENT ACCESS
            reference       operator[](size_type n);        //DONE
            const_reference operator[](size_type n) const;  //DONE
            const_reference at(size_type n) const;          //DONE
            reference       at(size_type n);                //DONE
            reference       front();                        //DONE
            const_reference front() const;                  //DONE
            reference       back();                         //DONE
            const_reference back() const;                   //DONE

            //ACCESSORS
            allocator_type  get_allocator() const;  //DONE

            //MODIFIERS
            template <class InputIterator>
                void    assign(InputIterator first, InputIterator last);
            void        assign(size_type n, const T& u);                    //DONE
            void        push_back(const T& x);
            void        pop_back();                                         //DONE
            //iterator  insert(iterator position, const T& x);
            //void      insert(iterator position, size_type n, const T& x);
            //template <class InputIterator>
                //void    insert(iterator position, InputIterator first, InputIterator last);
            //iterator  erase(iterator position);
            //iterator  erase(iterator first, iterator last);
            void        swap(vector<T, Allocator>&);
            void        clear();                                            //DONE

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

    template <class T, class Allocator>
    vector<T, Allocator>::vector(const vector<T, Allocator>& x)
    {
        _array = 0;
        *this = x;
    }

    template <class T, class Allocator>
    vector<T, Allocator>&   vector<T, Allocator>::operator=(const vector<T, Allocator>& x)
    {
        if (this != &x)
        {
            std::cout << "Assignation here" << std::endl;
        }
        return (*this);
    }

//DESTRUCTOR

    template <class T, class Allocator>
    vector<T, Allocator>::~vector()
    {
        for (size_type i = 0; i < _capacity; i++)
            _alloc.destroy(_array + i);
        _alloc.deallocate(_array, _capacity);
    }

//CAPACITY

    template <class T, class Allocator>
    typename vector<T, Allocator>::size_type   vector<T, Allocator>::size() const
    {
        return (_size);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::size_type   vector<T, Allocator>::max_size() const
    {
        return (_alloc.max_size());
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::size_type   vector<T, Allocator>::capacity() const
    {
        return (_capacity);
    }

    template <class T, class Allocator>
    bool    vector<T, Allocator>::empty() const
    {
        return (_size == 0 ? true : false);
    }

//ELEMENT ACCESS

    template <class T, class Allocator>
    typename vector<T, Allocator>::reference    vector<T, Allocator>::operator[](size_type n)
    {
        return (_array[n]);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::const_reference    vector<T, Allocator>::operator[](size_type n) const
    {
        return (_array[n]);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::const_reference    vector<T, Allocator>::at(size_type n) const
    {
        if (n >= _size)
            throw (std::out_of_range("Out of range"));
        return (_array[n]);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::reference    vector<T, Allocator>::at(size_type n)
    {
        if (n >= _size)
            throw (std::out_of_range("Out of range"));
        return (_array[n]);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::reference    vector<T, Allocator>::front()
    {
        return (_array[0]);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::const_reference    vector<T, Allocator>::front() const
    {
        return (_array[0]);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::reference    vector<T, Allocator>::back()
    {
        return (_array[_size - 1]);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::const_reference    vector<T, Allocator>::back() const
    {
        return (_array[_size - 1]);
    }

//ACCESSORS

    template <class T, class Allocator>
    typename vector<T, Allocator>::allocator_type  vector<T, Allocator>::get_allocator() const
    {
        return (_alloc);
    }

//MODIFIERS

    template <class T, class Allocator>
    void    vector<T, Allocator>::assign(size_type n, const T& u)
    {
        this->clear();
        if (n > _capacity)
        {
            _alloc.deallocate(_array, _capacity);
            _capacity = n;
            _array = _alloc.allocate(_capacity);
        }
        for (size_type i = 0; i < n; i++)
            _alloc.construct(_array + i, u);
        _size = n;
    }

    template <class T, class Allocator>
    void    vector<T, Allocator>::pop_back()
    {
        _alloc.destroy(_array + _size - 1);
        _size--;
    }

    template <class T, class Allocator>
    void    vector<T, Allocator>::clear()
    {
        while (!this->empty())
            this->pop_back();
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