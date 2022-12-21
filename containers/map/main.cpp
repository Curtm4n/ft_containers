/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:27:15 by cdapurif          #+#    #+#             */
/*   Updated: 2022/12/21 17:30:48 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "../../utils/Colors.hpp"

#include <map>
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
    std::cout << Green << " **************** Tests for namespace " << PRINT << " **************** " << Reset << std::endl;

    std::cout << "Hello map? :) " << std::endl;

    return (0);
}