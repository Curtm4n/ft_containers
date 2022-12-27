/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:27:15 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/27 19:38:05 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "../../utils/Colors.hpp"

#include <map>
#include <cstddef>
#include <iostream>

#if NSP
# define NAMESPACE std
# define PRINT "std"
#else
# define NAMESPACE ft
# define PRINT "ft"
#endif

int main(void)
{
    std::cout << Green << " **************** Tests for namespace " << PRINT << " **************** " << Reset << std::endl << std::endl;
    typedef NAMESPACE::map<int, int>::iterator iterator; //MIGHT CONSIDER MOVING THIS

    std::cout << Green << "Test default constructor for map (no output)" << Reset << std::endl;
    {
        NAMESPACE::map<int, int>    map1;
    }

    std::cout << Green << "Test range constructor for map (1-10)" << Reset << std::endl;
    {
        NAMESPACE::map<int, int>    map1;
        for (int i = 1; i <= 10; i++)
            map1[i] = i;

        iterator it = map1.begin();
        for (; it != map1.end(); ++it)
            std::cout << (*it).second << " ";
        std::cout << std::endl;

        std::cout << (*map1.find(10)).second << std::endl;
        std::cout << (*map1.end()).second << std::endl;
    }

    return (0);
}