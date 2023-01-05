/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:27:15 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/05 14:59:47 by cdapurif         ###   ########.fr       */
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

    //DEFAULT CONSTRUCTOR
    std::cout << Green << "Test default constructor for map (no output)" << Reset << std::endl << std::endl;
    {
        NAMESPACE::map<int, int>    map1;
    }

    //OPERATOR [] AND ITERATORS
    std::cout << Green << "Test operator[] for adding pairs (1-10) and iterators" << Reset << std::endl;
    {
        NAMESPACE::map<int, int>    map1;

        for (int i = 1; i <= 10; i++)
            map1[i] = i;

        iterator it = map1.begin();

        for (; it != map1.end(); ++it)
            std::cout << it->second << " ";
        std::cout << std::endl;

        std::cout << Green << "Print the value of the pair with the key 10" << Reset << std::endl;
        std::cout << (*map1.find(10)).second << std::endl << std::endl;
    }

    //TIME TEST
    std::cout << Green << "Test time" << Reset << std::endl;
    {
        NAMESPACE::map<int, std::string>    map1;

        for (int i = 0; i < 100000; ++i)
            map1[i];
    }

    //COPY CONSTRUCTOR, INSERT, SIZE, EMPTY AND ASSIGNATION OPERATOR
    std::cout << std::endl <<Green << "Test for insert method, copy constructor, size, empty and assignation operator" << Reset << std::endl;
    {
        NAMESPACE::map<int, int>    map1;

        for (int i = 0; i < 10; ++i)
            map1.insert(NAMESPACE::make_pair(i, i));

        NAMESPACE::map<int, int>    map2(map1);

        iterator it = map2.begin();
        
        for (; it != map2.end(); ++it)
            std::cout << it->second << " ";
        std::cout << std::endl;

        std::cout << Green << "we clear map2 which was a copy of map1" << Reset << std::endl;
        map2.clear();

        std::cout << "map1 size: " << map1.size() << " and map2 size: " << map2.size() << std::endl;
        std::cout << "is map1 empty (0:no/1:yes)? : " << map1.empty() << " and map2? : " << map2.empty() << std::endl;

        std::cout << Green << "we use assignation operator to assign map1 to map2" << Reset << std::endl;
        map2 = map1;

        std::cout << "map1 size: " << map1.size() << " and map2 size: " << map2.size() << std::endl;
        std::cout << "is map1 empty (0:no/1:yes)? : " << map1.empty() << " and map2? : " << map2.empty() << std::endl;
    }

    //MAX SIZE TESTS
    std::cout << std::endl <<Green << "Test for max size for different kinds of map" << Reset << std::endl;
    {
        NAMESPACE::map<int, int>            map1;
        NAMESPACE::map<int, std::string>    map2;
        NAMESPACE::map<float, char>         map3;

        std::cout << Green << "we are testing three empty maps, map1<int, int>, map2<int, std::string>, map3<float, char> for their max_size" << Reset << std::endl;
        std::cout << "map1 max_size: " << map1.max_size() << std::endl;
        std::cout << "map2 max_size: " << map2.max_size() << std::endl;
        std::cout << "map3 max_size: " << map3.max_size() << std::endl;
    }

    //RANGE INSERT AND RANGE CONSTRUCT
    std::cout << std::endl <<Green << "Test for range construct and range insert" << Reset << std::endl;
    {
        NAMESPACE::map<int, int>    map1;

        for (int i = 0; i < 10; ++i)
            map1.insert(NAMESPACE::make_pair(i, i));

        NAMESPACE::map<int, int>    map2(map1.begin(), map1.end());

        iterator it = map2.begin();
        
        for (; it != map2.end(); ++it)
            std::cout << it->second << " ";
        std::cout << std::endl;

        std::cout << Green << "Here we clear map1 and insert to it the content of map2" << Reset << std::endl;
        map1.clear();
        map1.insert(map2.begin(), map2.end());

        iterator it2 = map1.begin();
        
        for (; it2 != map1.end(); ++it2)
            std::cout << it2->second << " ";
        std::cout << std::endl;
    }

    //FIND AND COUNT
    std::cout << std::endl <<Green << "Test for find and count methods" << Reset << std::endl;
    {
        NAMESPACE::map<int, float>  map1;

        for (int i = 1; i <= 10; ++i)
            map1[i] = (float)i + 0.563;

        std::cout << "we print the value of the pair with key 7: " << (*map1.find(7)).second << std::endl;
        std::cout << "how many pair with key 56? : " << map1.count(56) << " | and with key 3? : " << map1.count(3) << std::endl;
    }

    return (0);
}