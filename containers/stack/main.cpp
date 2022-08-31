/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:55:43 by cdapurif          #+#    #+#             */
/*   Updated: 2022/08/30 13:05:15 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "Colors.hpp"
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

    std::cout << Green << " **************** Tests for namespace " << PRINT << " **************** " << Reset << std::endl;
    std::cout << test.empty() << std::endl;
    test.push(42);
    NAMESPACE::stack<int>   test2;
    std::cout << (test2 < test) << std::endl;
    std::cout << PRINT << std::endl;
    return (0);
}