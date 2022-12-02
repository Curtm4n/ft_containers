/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:27:03 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/02 15:51:07 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "ItVector.hpp"
# include "../../utils/iterator.hpp"
# include "../../utils/algorithms.hpp"
# include "../../utils/type_traits.hpp"

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
            typedef ItVector<T>                             iterator;
            typedef ItVector<const T>                       const_iterator;
            typedef std::size_t                             size_type;
            typedef std::ptrdiff_t                          difference_type;
            typedef T                                       value_type;
            typedef Allocator                               allocator_type;
            typedef typename Allocator::pointer             pointer;
            typedef typename Allocator::const_pointer       const_pointer;
            typedef ft::reverse_iterator<iterator>          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

            //CONSTRUCTORS
            explicit    vector(const Allocator& = Allocator());                                                                                                 //Default constructor       //DONE
            explicit    vector(size_type n, const T& value = T(), const Allocator& = Allocator());                                                              //Parametric constructor    //DONE
            template <class InputIterator>
                vector(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const Allocator& = Allocator());  //Range Constructor         //DONE
            vector(const vector<T, Allocator>& x);                                                                                                              //Copy constructor          //DONE
            vector<T, Allocator>&   operator=(const vector<T, Allocator>& x);                                                                                   //Assignation operator      //DONE

            //DESTRUCTOR
            ~vector();

            //ITERATORS
            iterator                  begin();          //DONE
            const_iterator            begin() const;    //DONE
            iterator                  end();            //DONE
            const_iterator            end() const;      //DONE
            reverse_iterator          rbegin();         //DONE
            const_reverse_iterator    rbegin() const;   //DONE
            reverse_iterator          rend();           //DONE
            const_reverse_iterator    rend() const;     //DONE

            //CAPACITY
            size_type   size() const;                       //DONE
            size_type   max_size() const;                   //DONE
            void        resize(size_type sz, T c = T());    //DONE
            size_type   capacity() const;                   //DONE
            bool        empty() const;                      //DONE
            void        reserve(size_type n);               //DONE

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
                void    assign(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last);                      //DONE
            void        assign(size_type n, const T& u);                                                                                                    //DONE
            void        push_back(const T& x);                                                                                                              //DONE
            void        pop_back();                                                                                                                         //DONE
            iterator  insert(iterator position, const T& x);                                                                                                //DONE
            void      insert(iterator position, size_type n, const T& x);                                                                                   //DONE
            template <class InputIterator>
                void    insert(iterator position, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last);
            iterator  erase(iterator position);                                                                                                             //DONE
            iterator  erase(iterator first, iterator last);                                                                                                 //DONE
            void        swap(vector<T, Allocator>&);                                                                                                        //DONE
            void        clear();                                                                                                                            //DONE

        private:

            pointer         _array;
            size_type       _size;
            size_type       _capacity;
            allocator_type  _alloc;
    };

//CONSTRUCTORS

    template <class T, class Allocator>
    vector<T, Allocator>::vector(const Allocator& alloc) : _array(0), _size(0), _capacity(0), _alloc(alloc) {}

    template <class T, class Allocator>
    vector<T, Allocator>::vector(size_type n, const T& value, const Allocator& alloc) : _array(0), _size(0), _capacity(0), _alloc(alloc)
    {
        if (n)
        {
            _array = _alloc.allocate(n);
            _capacity = n;
            for (size_type i = 0; i < n; i++)
            {
                _alloc.construct(_array + i, value);
                _size++;
            }
        }
    }

    template <class T, class Allocator>
    template <class InputIterator>
    vector<T, Allocator>::vector(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const Allocator& alloc) : _array(0), _size(0), _capacity(0), _alloc(alloc)
    {
        size_type   sz = std::distance(first, last);    //WON'T WORK ON INPUT ITERATORS BUT OK FOR ALL OTHER TYPES (for input iterators, need to be reallocate for every element, check tag dispatching)

        if (sz)
        {
            _array = _alloc.allocate(sz);
            _capacity = sz;
            for (; first != last; first++)
            {
                _alloc.construct(_array + _size, *first);
                _size++;
            }
        }
    }

    template <class T, class Allocator>
    vector<T, Allocator>::vector(const vector<T, Allocator>& x) : _array(0), _size(0), _capacity(0), _alloc(x.get_allocator())
    {
        if (x.capacity())
        {
            _array = _alloc.allocate(x.capacity());
            _capacity = x.capacity();
            for (size_type i = 0; i < x.size(); i++)
            {
                _alloc.construct(_array + i, x[i]);
                _size++;
            }
        }
    }

    template <class T, class Allocator>
    vector<T, Allocator>&   vector<T, Allocator>::operator=(const vector<T, Allocator>& x)
    {
        if (this == &x)
            return (*this);
        if (x.size() > _capacity)
        {
            vector<T, Allocator>    tmp(x);

            this->swap(tmp);
        }
        else
        {
            if (x.size() <= _size)
            {
                iterator it = std::copy(x.begin(), x.end(), this->begin());
                for (; it < this->end(); it++)
                    _alloc.destroy(it.getPointer());
                _size = x.size();
            }
            else
            {
                std::copy(x.begin(), x.begin() + _size, this->begin());
                for (; _size < x.size(); _size++)
                    _alloc.construct(_array + _size, x[_size]);
            }
        }
        return (*this);
    }

//DESTRUCTOR

    template <class T, class Allocator>
    vector<T, Allocator>::~vector()
    {
        if (_capacity)
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(_array + i);
            _alloc.deallocate(_array, _capacity);
        }
    }

//ITERATORS
            
    template <class T, class Allocator>        
    typename vector<T, Allocator>::iterator vector<T, Allocator>::begin()
    {
        return (_array);
    }

    template <class T, class Allocator>        
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const
    {
        return (_array);
    }

    template <class T, class Allocator>        
    typename vector<T, Allocator>::iterator vector<T, Allocator>::end()
    {
        return (_array + _size);
    }

    template <class T, class Allocator>        
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const
    {
        return (_array + _size);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin()
    {
        return (reverse_iterator(this->end()));
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin() const
    {
        return (reverse_iterator(this->end()));
    }
    
    template <class T, class Allocator>
    typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend()
    {
        return (reverse_iterator(this->begin()));
    }
    
    template <class T, class Allocator>
    typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend() const
    {
        return (reverse_iterator(this->begin()));
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
    void    vector<T, Allocator>::resize(size_type sz, T c)
    {
        if (sz < _size)
        {
            for (size_type i = sz; i < _size; i++)
                _alloc.destroy(_array + i);
            _size = sz;
        }
        else if (sz > _size)
        {
            if (sz > _capacity)
                this->reserve(sz);
            for (size_type i = _size; i < sz; i++)
            {
                _alloc.construct(_array + i, c);
                _size++;
            }
        }
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

    template <class T, class Allocator>
    void    vector<T, Allocator>::reserve(size_type n)
    {
        pointer     tmp;
        size_type   cptr;

        if (n > _capacity)
        {
            if (n > this->max_size())
                throw (std::length_error("Length error"));
            tmp = _alloc.allocate(n);
            cptr = 0;
            try
            {
                for (size_type i = 0; i < _size; i++)
                {
                    _alloc.construct(tmp + i, _array[i]);
                    cptr++;
                }
            }
            catch(const std::exception& e)
            {
                for (size_type i = 0; i < cptr; i++)
                    _alloc.destroy(tmp + i);
                _alloc.deallocate(tmp, n);
                throw (std::bad_alloc());
            }
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(_array + i);
            if (_capacity)
                _alloc.deallocate(_array, _capacity);
            _capacity = n;
            _array = tmp;
        }
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
    template <class InputIterator>
    void    vector<T, Allocator>::assign(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
    {
        size_type   sz = std::distance(first, last);    //WON'T WORK ON INPUT ITERATORS BUT OK FOR ALL OTHER TYPES (for input iterators, need to be reallocate for every element, check tag dispatching)
        pointer     tmp;

        if (sz > _capacity)
            tmp = _alloc.allocate(sz);
        this->clear();
        if (sz > _capacity)
        {
            if (_capacity)
                _alloc.deallocate(_array, _capacity);
            _capacity = sz;
            _array = tmp;
        }
        for (; first != last; first++)
        {
            _alloc.construct(_array + _size, *first);
            _size++;
        }
    }

    template <class T, class Allocator>
    void    vector<T, Allocator>::assign(size_type n, const T& u)
    {
        pointer tmp;

        if (n > _capacity)
            tmp = _alloc.allocate(n);
        this->clear();
        if (n > _capacity)
        {
            if (_capacity)
                _alloc.deallocate(_array, _capacity);
            _capacity = n;
            _array = tmp;
        }
        for (size_type i = 0; i < n; i++)
        {
            _alloc.construct(_array + i, u);
            _size++;
        }
    }

    template <class T, class Allocator>
    void    vector<T, Allocator>::push_back(const T& x)
    {
        size_type   newCap;

        if (_size == _capacity)
        {
            if (_capacity == this->max_size())
                return ;
            newCap = 2 * _capacity;
            if (newCap == 0)
                newCap = 1;
            else if (newCap > this->max_size())
                newCap = this->max_size();
            this->reserve(newCap);
        }
        _alloc.construct(_array + _size, x);
        _size++;
    }

    template <class T, class Allocator>
    void    vector<T, Allocator>::pop_back()
    {
        _alloc.destroy(_array + _size - 1);
        _size--;
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(iterator position, const T& x)
    {
        if (_size == _capacity)
        {
            size_type index = std::distance(this->begin(), position);
            this->reserve(_capacity + 1);
            position = this->begin() + index;
        }
        if (position == this->end())
        {
            _alloc.construct(_array + _size, x);
            _size++;
        }
        else
        {
            _alloc.construct(_array + _size, _array[_size - 1]);
            _size++;
            for (iterator itEnd = this->end() - 2; itEnd > position; itEnd--)
                *itEnd = *(itEnd - 1);
            *position = x;
        }
        return (position);
    }

    template <class T, class Allocator>
    void    vector<T, Allocator>::insert(iterator position, size_type n, const T& x)
    {
        size_type   indexPos = std::distance(this->begin(), position);
        
        if (!n)
            return ;
        if (_size + n > _capacity)
        {
            this->reserve(_size + n);
            position = this->begin() + indexPos;
        }
        if (position == this->end())
        {
            for (size_type i = 0; i < n; i++)
            {
                _alloc.construct(_array + _size, x);
                _size++;
            }
        }
        else
        {
            size_type prevEnd = _size;
            size_type prevValIndex = indexPos + n;    //index where prev values are relocated

            if (prevValIndex < _size)
            {
                for (size_type i = prevEnd - n; i < prevEnd; i++)
                {
                    _alloc.construct(_array + _size, _array[i]);
                    _size++;
                }
                for (size_type i = prevValIndex; i < prevEnd; i++)
                    _array[i] = _array[i - n];
                for (; indexPos < prevValIndex; indexPos++)
                    _array[indexPos] = x;
            }
            else
            {
                for (; _size < prevValIndex; _size++)
                    _alloc.construct(_array + _size, x);
                for (size_type i = indexPos; i < prevEnd; i++)
                {
                    _alloc.construct(_array + _size, _array[i]),
                    _size++;
                    _array[i] = x;
                }
            }
        }
    }

    template <class T, class Allocator>
    template <class InputIterator>
    void    vector<T, Allocator>::insert(iterator position, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
    {
        size_type   n = std::distance(first, last);
        size_type   indexPos = std::distance(this->begin(), position);
        
        if (!n)
            return ;
        if (_size + n > _capacity)
        {
            this->reserve(_size + n);
            position = this->begin() + indexPos;
        }
        if (position == this->end())
        {
            for (size_type i = 0; i < n; i++)
            {
                _alloc.construct(_array + _size, *first++);
                _size++;
            }
        }
        else
        {
            size_type prevEnd = _size;
            size_type prevValIndex = indexPos + n;    //index where prev values are relocated

            if (prevValIndex < _size)
            {
                for (size_type i = prevEnd - n; i < prevEnd; i++)
                {
                    _alloc.construct(_array + _size, _array[i]);
                    _size++;
                }
                for (size_type i = prevValIndex; i < prevEnd; i++)
                    _array[i] = _array[i - n];
                for (; indexPos < prevValIndex; indexPos++)
                    _array[indexPos] = *first++;
            }
            else
            {
                InputIterator   tmp = first;
                
                for (size_type i = std::distance(position, this->end()); i > 0; i--)
                    tmp++;
                for (; _size < prevValIndex; _size++)
                    _alloc.construct(_array + _size, *tmp++);
                for (size_type i = indexPos; i < prevEnd; i++)
                {
                    _alloc.construct(_array + _size, _array[i]),
                    _size++;
                    _array[i] = *first++;
                }
            }
        }
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator position)
    {
        if (position + 1 != this->end())
            std::copy(position + 1, this->end(), position);
        --_size;
        _alloc.destroy(_array + _size);
        return (position);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator first, iterator last)
    {
        if (first != last)
        {
            iterator    it = this->end() - std::distance(first, last);

            if (last != this->end())
                std::copy(last, this->end(), first);
            for (; it < this->end(); it++)
                _alloc.destroy(it.getPointer());
            _size -= std::distance(first, last);
        }
        return (first);
    }

    template <class T, class Allocator>
    void    vector<T, Allocator>::swap(vector<T, Allocator>& x)
    {
        pointer     tmp;
        size_type   val;

        tmp = _array;
        _array = x._array;
        x._array = tmp;

         val = _size;
        _size = x._size;
        x._size = val;

        val = _capacity;
        _capacity = x._capacity;
        x._capacity = val;
    }

    template <class T, class Allocator>
    void    vector<T, Allocator>::clear()
    {
        while (!this->empty())
            this->pop_back();
    }

//OPERATORS

    template <class T, class Allocator>
    bool    operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
    {
        if (x.size() == y.size())
            return (equal(x.begin(), x.end(), y.begin()));
        return (false);
    }

    template <class T, class Allocator>
    bool    operator< (const vector<T, Allocator>& x, const vector<T, Allocator>& y)
    {
        return (lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
    }

    template <class T, class Allocator>
    bool    operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
    {
        return (!(x == y));
    }

    template <class T, class Allocator>
    bool    operator> (const vector<T, Allocator>& x, const vector<T, Allocator>& y)
    {
        return (y < x);
    }

    template <class T, class Allocator>
    bool    operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
    {
        return (!(x < y));
    }

    template <class T, class Allocator>
    bool    operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
    {
        return (!(y < x));
    }

//SPECIALIZED ALGORITHMS

    template <class T, class Allocator>
    void    swap(vector<T, Allocator>& x, vector<T, Allocator>& y)
    {
        x.swap(y);
    }
}

#endif