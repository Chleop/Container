/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_integral.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:05:14 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/21 15:23:03 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <type_traits>
#include "../is_integral.hpp"

// ATTENTION : LES TESTS SUR LA STD NE PASSENT PAS AVEC LE FLAG C++98!

int main (void)
{
// ORIGINAL WITH STD LIBRARY TESTS
    std::cout << "\033[32m### TESTING STANDARD LIBRARY\033[37m" << std::endl;
    // std::cout << "char: " << std::is_integral<char>::value << std::endl;
    // std::cout << "int: " << std::is_integral<int>::value << std::endl;
    // std::cout << "float: " << std::is_integral<float>::value << std::endl;
    // std::cout << "double: " << std::is_integral<double>::value << std::endl;
    // std::cout << "std::string: " << std::is_integral<std::string>::value << std::endl;
    // std::cout << "const char: " << std::is_integral<const char>::value << std::endl;
    // std::cout << "const int: " << std::is_integral<const int>::value << std::endl;
    // std::cout << "const float: " << std::is_integral<const float>::value << std::endl;
    // std::cout << "const double: " << std::is_integral<const double>::value << std::endl;
    // std::cout << "const std::string: " << std::is_integral<const std::string>::value << std::endl;

// COPY WITH MY FT LIBRARY TESTS
    std::cout << std::endl << "\033[32m### TESTING MY FT LIBRARY\033[37m" << std::endl;
    std::cout << "char: " << ft::is_integral<char>::value << std::endl;
    std::cout << "int: " << ft::is_integral<int>::value << std::endl;
    std::cout << "float: " << ft::is_integral<float>::value << std::endl;
    std::cout << "double: " << ft::is_integral<double>::value << std::endl;
    std::cout << "std::string: " << ft::is_integral<std::string>::value << std::endl;
    std::cout << "const char: " << ft::is_integral<const char>::value << std::endl;
    std::cout << "const int: " << ft::is_integral<const int>::value << std::endl;
    std::cout << "const float: " << ft::is_integral<const float>::value << std::endl;
    std::cout << "const double: " << ft::is_integral<const double>::value << std::endl;
    std::cout << "const std::string: " << ft::is_integral<const std::string>::value << std::endl;
    return 0;
}