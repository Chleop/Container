/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_integral.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:05:14 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/20 18:49:26 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits>
// #include "is_integral.hpp"

// ATTENTION : LES TESTS NE PASSENT PAS AVEC C++98!!!!!!!!

int main (void)
{
// ORIGINAL WITH STD LIBRARY TESTS
    std::cout << "\033[32m### TESTING STANDARD LIBRARY\033[37m" << std::endl;
    std::cout << "char: " << std::is_integral<char>::value << std::endl;
    std::cout << "int: " << std::is_integral<int>::value << std::endl;
    std::cout << "float: " << std::is_integral<float>::value << std::endl;
    std::cout << "double: " << std::is_integral<double>::value << std::endl;
    std::cout << "std::string: " << std::is_integral<std::string>::value << std::endl;

// COPY WITH MY FT LIBRARY TESTS
    std::cout << std::endl << "\033[32m### TESTING MY FT LIBRARY\033[37m" << std::endl;
    // std::cout << "MY is_integral:" << std::endl;
    // std::cout << "char: " << ft::is_integral<char>() << std::endl;
    // std::cout << "int: " << ft::is_integral<int>() << std::endl;
    // std::cout << "float: " << ft::is_integral<float>() << std::endl;
    // std::cout << "double: " << ft::is_integral<double>() << std::endl;
    // std::cout << "std::string: " << ft::is_integral<std::string>() << std::endl;
    return 0;
}