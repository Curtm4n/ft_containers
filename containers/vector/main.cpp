/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:28:46 by cdapurif          #+#    #+#             */
/*   Updated: 2022/11/24 19:37:16 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "../../utils/Colors.hpp"
#include <vector>

#if NSP
# define NAMESPACE std
# define PRINT "std"
#else
# define NAMESPACE ft
# define PRINT "ft"
#endif

int main(void)
{
    std::cout << Green << " **************** Tests for namespace " << PRINT << " **************** " << Reset << std::endl;

    typedef NAMESPACE::vector<int>::iterator   iterator;


    // TEST FOR METHODS SIZE, CAPACITY, EMPTY, MAX_SIZE, OPERATOR[], AT, FRONT, BACK, POP_BACK, CLEAR AND ASSIGN    
    NAMESPACE::vector<int>  vector1(10, 42);
    
    std::cout << "size of vector1: " << vector1.size() << std::endl;
    std::cout << "capacity of vector1: " << vector1.capacity() << std::endl;
    std::cout << "vector1 empty? : " << vector1.empty() << std::endl;
    std::cout << "vector1 max size: " << vector1.max_size() << std::endl;
    vector1[5] = 486;
    try
    {
        std::cout << "element at index 5 of vector1: " << vector1.at(5) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    vector1[0] = 4242;
    vector1.at(9) = 123;
    std::cout << "front element of vector1: " << vector1.front() << std::endl;
    std::cout << "back element of vector1: " << vector1.back() << std::endl;
    std::cout << "using pop_back on vector1" << std::endl;
    vector1.pop_back();
    std::cout << "size of vector1: " << vector1.size() << std::endl;
    std::cout << "capacity of vector1: " << vector1.capacity() << std::endl;
    std::cout << "back element of vector1: " << vector1.back() << std::endl;
    std::cout << "using clear on vector1" << std::endl;
    vector1.clear();
    std::cout << "size of vector1: " << vector1.size() << std::endl;
    std::cout << "capacity of vector1: " << vector1.capacity() << std::endl;
    std::cout << "Now we assign 15 times the value 465 to vector1" << std::endl;
    vector1.assign(15, 465);
    std::cout << "size of vector1: " << vector1.size() << std::endl;
    std::cout << "capacity of vector1: " << vector1.capacity() << std::endl;
    std::cout << "vector1 index 12: " << vector1[12] << std::endl;

    
    //TEST FOR METHOD RESIZE
    std::cout << std::endl << Green << "Tests for resize method" << Reset << std::endl;
    NAMESPACE::vector<NAMESPACE::vector<int> >  vector2(5, NAMESPACE::vector<int>(10, 255));
    std::cout << "Now we resize our vector2 of size 5 to size 10" << std::endl;
    vector2.resize(10, NAMESPACE::vector<int>(3, 88));
    std::cout << "size of vector2: " << vector2.size() << std::endl;
    std::cout << "capacity of vector2: " << vector2.capacity() << std::endl;

    
    //TEST FOR METHOD RESERVE
    std::cout << std::endl << Green << "Tests for reserve method" << Reset << std::endl;
    NAMESPACE::vector<int>  vector3(5, 42);
    std::cout << "Now we reserve a capacity of 10 for our vector3 (of capacity 5)" << std::endl;
    vector3.reserve(10);
    std::cout << "size of vector3: " << vector3.size() << std::endl;
    std::cout << "capacity of vector3: " << vector3.capacity() << std::endl;

    
    //TEST FOR METHOD SWAP
    std::cout << std::endl << Green << "Tests for swap method" << Reset << std::endl;
    std::cout << "second element, size and capacity of vector1 before swap: ";
    std::cout << vector1[1] << " " << vector1.size() << " " << vector1.capacity() << std::endl;
    std::cout << "second element, size and capacity of vector3 before swap: ";
    std::cout << vector3[1] << " " << vector3.size() << " " << vector3.capacity() << std::endl;
    std::cout << "Swapping vector1 and vector3" << std::endl;
    vector1.swap(vector3);
    std::cout << "second element, size and capacity of vector1 after swap: ";
    std::cout << vector1[1] << " " << vector1.size() << " " << vector1.capacity() << std::endl;
    std::cout << "second element, size and capacity of vector3 after swap: ";
    std::cout << vector3[1] << " " << vector3.size() << " " << vector3.capacity() << std::endl;

    
    //TEST FOR METHOD PUSH_BACK
    std::cout << std::endl << Green << "Tests for push_back method" << Reset << std::endl;
    vector1.reserve(11);
    std::cout << "size and capacity of vector1 before push_back: ";
    std::cout << vector1.size() << " " << vector1.capacity() << std::endl;
    for (int i = 1; i < 8; i++)
    {
        vector1.push_back(i);
        std::cout << vector1[vector1.size() - 1] << " ";
    }
    std::cout << std::endl;
    std::cout << "size and capacity of vector1 after push_back: ";
    std::cout << vector1.size() << " " << vector1.capacity() << std::endl;

    
    std::cout << std::endl << Green << "Tests for push_back method on empty vector" << Reset << std::endl;
    NAMESPACE::vector<int>  vector4;
    std::cout << "size and capacity of vector4 before push_back: ";
    std::cout << vector4.size() << " " << vector4.capacity() << std::endl;
    vector4.push_back(42);
    std::cout << "size and capacity of vector4 after push_back: ";
    std::cout << vector4.size() << " " << vector4.capacity() << std::endl;

    
    /*std::cout << std::endl << Green << "Tests for push_back method on max_size vector" << Reset << std::endl;
    std::cout << "max_size for vector4 <int>: " << vector4.max_size() << std::endl;
    vector4.clear();
    try
    {
        vector4.reserve(vector4.max_size() - 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "size and capacity of vector4 before push_back: ";
    std::cout << vector4.size() << " " << vector4.capacity() << std::endl;
    vector4.push_back(42);
    std::cout << "size and capacity of vector4 after push_back: ";
    std::cout << vector4.size() << " " << vector4.capacity() << std::endl;*/

    
    //TEST FOR SPECIALIZATION OF SWAP
    std::cout << Green << "Test for the specialized version of swap on vector2 and vector3" << Reset << std::endl;
    std::cout << "second element, size and capacity of vector1 before swap: ";
    std::cout << vector1[1] << " " << vector1.size() << " " << vector1.capacity() << std::endl;
    std::cout << "second element, size and capacity of vector3 before swap: ";
    std::cout << vector3[1] << " " << vector3.size() << " " << vector3.capacity() << std::endl;
    std::cout << "Swapping vector1 and vector3" << std::endl;
    NAMESPACE::swap(vector1, vector3);
    std::cout << "second element, size and capacity of vector1 after swap: ";
    std::cout << vector1[1] << " " << vector1.size() << " " << vector1.capacity() << std::endl;
    std::cout << "second element, size and capacity of vector3 after swap: ";
    std::cout << vector3[1] << " " << vector3.size() << " " << vector3.capacity() << std::endl;

    
    NAMESPACE::vector<int>  vector5;

    
    //TEST FOR DISTANCE BETWEEN ITERATORS
    std::cout << Green << "Test for calculing distance between two iterators" << Reset << std::endl;
    NAMESPACE::vector<int>  vector6;
    for (size_t i = 1; i <= 10; i++)
        vector6.push_back(i);
    
    iterator it = vector6.begin();
    std::cout << "distance: " << vector6.end() - it << std::endl;

    
    //TEST FOR RANGE CONSTRUCTOR
    std::cout << Green << "Test for range constructor" << Reset << std::endl;
    NAMESPACE::vector<int>  vector7(vector6.begin(), vector6.end());

    for (size_t i = 0; i < vector7.size(); i++)
        std::cout << vector7[i] << " ";
    std::cout << std::endl;

    
    //TEST FOR ASSIGN METHOD (RANGE VERSION)
    std::cout << Green << "Test for assign method (range version)" << Reset << std::endl;
    vector5.assign(vector6.begin(), vector6.end());

    for (size_t i = 0; i < vector5.size(); i++)
        std::cout << vector5[i] << " ";
    std::cout << std::endl;


    //TEST FOR ERASE METHOD
    std::cout << Green << "Test for erase method" << Reset << std::endl;
    vector5.erase(vector5.begin());

    for (iterator it = vector5.begin(); it != vector5.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;


    std::cout << Green << "Test for erase method with vector of vector of int (no output :) )" << Reset << std::endl;
    NAMESPACE::vector<NAMESPACE::vector<int> >  vector8(10, NAMESPACE::vector<int>(10, 255));
    vector8.erase(vector8.begin() + 6);

    
    return (0);
}