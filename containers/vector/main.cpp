/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:28:46 by cdapurif          #+#    #+#             */
/*   Updated: 2022/10/18 18:17:41 by cdapurif         ###   ########.fr       */
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
    //NAMESPACE::vector<int>  vector1;
    NAMESPACE::vector<int>  vector1(static_cast<size_t>(10), 42);
    //NAMESPACE::vector<std::vector<int> >  vector1(static_cast<size_t>(10), std::vector<int>(20, 963));
    
    std::cout << Green << " **************** Tests for namespace " << PRINT << " **************** " << Reset << std::endl;
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
    vector1.assign(static_cast<size_t>(15), 465);
    std::cout << "size of vector1: " << vector1.size() << std::endl;
    std::cout << "capacity of vector1: " << vector1.capacity() << std::endl;
    std::cout << "vector1 index 12: " << vector1[12] << std::endl;

    std::cout << std::endl << Green << "Tests for resize method" << Reset << std::endl;
    NAMESPACE::vector<int>  vector2(static_cast<size_t>(0));
    //NAMESPACE::vector<NAMESPACE::vector<int> >  vector2(static_cast<size_t>(5), NAMESPACE::vector<int>(static_cast<size_t>(10), 255));
    //std::cout << "Now we resize our vector2 of size 5 to size 10" << std::endl;
    //vector2.resize(static_cast<size_t>(10), NAMESPACE::vector<int>(static_cast<size_t>(3), 88));
    //std::cout << "size of vector2: " << vector2.size() << std::endl;
    //std::cout << "capacity of vector2: " << vector2.capacity() << std::endl;

    return (0);
}