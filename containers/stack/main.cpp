/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:55:43 by cdapurif          #+#    #+#             */
/*   Updated: 2022/09/07 14:39:05 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "../../utils/Colors.hpp"
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
    NAMESPACE::stack<int>   test2;

    std::cout << Green << " **************** Tests for namespace " << PRINT << " **************** " << Reset << std::endl;
    std::cout << "NOTE: for boolean functions 1 means true and 0 false" << std::endl << std::endl;

    std::cout << Green << "METHODS" << Reset << std::endl;
    std::cout << "test for empty method: " << test.empty() << std::endl;
    std::cout << "test for size method: " << test.size() << std::endl;
    std::cout << "test for push: **push 42 in test**" << std::endl;
    test.push(42);
    std::cout << "test for size method: " << test.size() << std::endl;
    std::cout << "test for top method: " << test.top() << std::endl;
    std::cout << "test for pop method" << std::endl;
    test.pop();
    std::cout << "test for size method: " << test.size() << std::endl << std::endl;
    
    
    std::cout << Green << "COMPARISON OPERATORS" << Reset << std::endl;
    std::cout << "test for test2 less than test (both empty): "<< (test2 < test) << std::endl;
    std::cout << "test for test2 less or equal than test (both empty): "<< (test2 <= test) << std::endl;
    std::cout << "test for test2 more than test (both empty): "<< (test2 > test) << std::endl;
    std::cout << "test for test2 more or equal than test (both empty): "<< (test2 >= test) << std::endl;
    std::cout << "test for test2 equal test (both empty): "<< (test2 == test) << std::endl;
    std::cout << "test for test2 different than test (both empty): "<< (test2 != test) << std::endl;
    return (0);
}