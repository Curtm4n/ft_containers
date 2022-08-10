/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:53:42 by cdapurif          #+#    #+#             */
/*   Updated: 2022/08/10 15:21:24 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <vector>

namespace ft
{
    template<class T, class Container = std::vector<T> >
    class stack
    {

        public:

            typedef typename Container::value_type  value_type;
            typedef typename Container::size_type   size_type;
            typedef          Container              container_type;

        protected:

            Container   c;

        public:

            explicit            stack(const Container& cont = Container()) : c(cont) {}

            bool                empty() const               { return c.empty(); }
            size_type           size() const                { return c.size(); }
            value_type&         top()                       { return c.back(); }
            const value_type&   top() const                 { return c.back(); }
            void                push(const value_type& x)   { c.push_back(x); }
            void                pop()                       { c.pop_back(); }

            friend bool operator<(const stack<T, Container>& x, const stack<T, Container>& y)   { return (x.c < y.c); }
            friend bool operator>(const stack<T, Container>& x, const stack<T, Container>& y)   { return (x.c > y.c); }
            friend bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)  { return (x.c <= y.c); }
            friend bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)  { return (x.c >= y.c); }
            friend bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)  { return (x.c == y.c); }
            friend bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)  { return (x.c != y.c); }

    };
}

#endif