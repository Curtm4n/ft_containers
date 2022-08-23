/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:55:43 by cdapurif          #+#    #+#             */
/*   Updated: 2022/08/23 15:58:14 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>

#if NSP
# define NAMESPACE std
# define PRINT "std"
#else
# define NAMESPACE ft
# define PRINT "ft"
#endif


int main(void)
{
    NAMESPACE::stack<int>   test;

    std::cout << test.empty() << std::endl;
    test.push(42);
    NAMESPACE::stack<int>   test2;
    std::cout << (test2 < test) << std::endl;
    std::cout << PRINT << std::endl;
    return (0);
}