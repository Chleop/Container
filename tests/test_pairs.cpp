/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pairs.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:44:14 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/22 16:08:07 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <iostream>
#include "tests.hpp"

void test_pairs(void)
{
    std::string str = "kiki";

// TEST 1
    LIB_PAIR <int, char> p1;
    std::cout << p1.first << std::endl;
    std::cout << p1.second << std::endl;
// TEST 2  
    LIB_PAIR <int, char> mypair;
    mypair.first = 100;
    mypair.second = 'G';
    std::cout << mypair.first << std::endl;
    std::cout << mypair.second << std::endl;
// TEST 3
    LIB_PAIR <int, std::string> p2(1, str);
    std::cout << p2.first << std::endl;
    std::cout << p2.second << std::endl;
// TEST 4
    LIB_PAIR <int, std::string> p3 (p2);
    std::cout << p3.first << std::endl;
    std::cout << p3.second << std::endl;
// TEST 5
    LIB_PAIR <double, std::string> p4;
    p4 = LIB_MAKE_PAIR(2.3, str);
    std::cout << p4.first << std::endl;
    std::cout << p4.second << std::endl;
// TEST 6
    LIB_PAIR<char, int> pair1 = LIB_MAKE_PAIR('A', 1);
    std::cout << pair1.first << std::endl;
    std::cout << pair1.second << std::endl;
// TEST 7
    LIB_PAIR <int, std::string> p5(2, "Thomas");
    LIB_PAIR <int, std::string> p6(1, "Wen");
    LIB_PAIR <int, std::string> p7(1, "Amber");
    std::cout << "inferieur : " << (p5 < p6) << std::endl;
    std::cout << "superieur : " << (p5 > p6) << std::endl;
    std::cout << "egal      : " << (p5 == p6) << std::endl;
    std::cout << "different : " << (p5 != p6) << std::endl;
    std::cout << "inferieur : " << (p7 < p6) << std::endl;
    std::cout << "superieur : " << (p7 > p6) << std::endl;
    std::cout << "egal      : " << (p7 == p6) << std::endl;
    std::cout << "different : " << (p7 != p6) << std::endl;
// TEST 8
    LIB_PAIR <int, std::string> p8;
    p8 = p6;
    std::cout << p8.first << std::endl;
    std::cout << p8.second << std::endl;
    return;
}