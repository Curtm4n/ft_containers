/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:28:46 by cdapurif          #+#    #+#             */
/*   Updated: 2022/10/12 16:04:22 by cdapurif         ###   ########.fr       */
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

    return (0);
}