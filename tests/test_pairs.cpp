/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pairs.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:44:14 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/20 16:54:41 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <iostream>
#include "../pairs.hpp"

int main(void)
{

// ATTENTION CE TEST FONCTIONNE SI ON DONNE AUTRE CHOSE QU'UN STRING A MAKE_PAIR
// POUR UNE RAISON ENCORE INCONNUE
// "error: array initializer must be an initializer list or string literal"
    
// ORIGINAL WITH STD LIBRARY TESTS
    std::cout << "\033[32m### TESTING STANDARD LIBRARY\033[37m" << std::endl;
// TEST 1
    std::pair <int, char> p1;
    std::cout << p1.first << std::endl;
    std::cout << p1.second << std::endl;
// TEST 2  
    std::pair <int, char> mypair;
    mypair.first = 100;
    mypair.second = 'G';
    std::cout << mypair.first << std::endl;
    std::cout << mypair.second << std::endl;
// TEST 3
    std::pair <int, std::string> p2(1, "coucou");
    std::cout << p2.first << std::endl;
    std::cout << p2.second << std::endl;
// TEST 4
    std::pair <int, std::string> p3 (p2);
    std::cout << p3.first << std::endl;
    std::cout << p3.second << std::endl;
// TEST 5
    std::pair <double, std::string> p4;
    p4 = std::make_pair(2.3, "kiki");
    std::cout << p4.first << std::endl;
    std::cout << p4.second << std::endl;
// TEST 6
    std::pair<char, int> pair1 = std::make_pair('A', 1);
    std::cout << pair1.first << std::endl;
    std::cout << pair1.second << std::endl;
// TEST 7
    std::pair <int, std::string> p5(2, "Thomas");
    std::pair <int, std::string> p6(1, "Wen");
    std::pair <int, std::string> p7(1, "Amber");
    std::cout << "inferieur : " << (p5 < p6) << std::endl;
    std::cout << "superieur : " << (p5 > p6) << std::endl;
    std::cout << "egal      : " << (p5 == p6) << std::endl;
    std::cout << "different : " << (p5 != p6) << std::endl;
    std::cout << "inferieur : " << (p7 < p6) << std::endl;
    std::cout << "superieur : " << (p7 > p6) << std::endl;
    std::cout << "egal      : " << (p7 == p6) << std::endl;
    std::cout << "different : " << (p7 != p6) << std::endl;
// TEST 8
    std::pair <int, std::string> p8;
    p8 = p6;
    std::cout << p8.first << std::endl;
    std::cout << p8.second << std::endl;
    
// COPY WITH MY FT LIBRARY TESTS
    std::cout << std::endl << "\033[32m### TESTING MY FT LIBRARY\033[37m" << std::endl;
// TEST 1
    ft::pair <int, char> t1;
    std::cout << t1.first << std::endl;
    std::cout << t1.second << std::endl;
// TEST 2  
    ft::pair <int, char> t2;
    t2.first = 100;
    t2.second = 'G';
    std::cout << t2.first << std::endl;
    std::cout << t2.second << std::endl;
// TEST 3
    ft::pair <int, std::string> t3(1, "coucou");
    std::cout << t3.first << std::endl;
    std::cout << t3.second << std::endl;
// TEST 4
    ft::pair <int, std::string> t4 (t3);
    std::cout << t4.first << std::endl;
    std::cout << t4.second << std::endl;
// TEST 5
    ft::pair <double, std::string> t5;
    t5 = ft::make_pair(2.3, std::string("kiki"));
    std::cout << t5.first << std::endl;
    std::cout << t5.second << std::endl;
// TEST 6
    ft::pair<char, int> pair2 = ft::make_pair('A', 1);
    std::cout << pair2.first << std::endl;
    std::cout << pair2.second << std::endl;
// TEST 7
    ft::pair <int, std::string> tp5(2, "Thomas");
    ft::pair <int, std::string> tp6(1, "Wen");
    ft::pair <int, std::string> tp7(1, "Amber");
    std::cout << "inferieur : " << (tp5 < tp6) << std::endl;
    std::cout << "superieur : " << (tp5 > tp6) << std::endl;
    std::cout << "egal      : " << (tp5 == tp6) << std::endl;
    std::cout << "different : " << (tp5 != tp6) << std::endl;
    std::cout << "inferieur : " << (tp7 < tp6) << std::endl;
    std::cout << "superieur : " << (tp7 > tp6) << std::endl;
    std::cout << "egal      : " << (tp7 == tp6) << std::endl;
    std::cout << "different : " << (tp7 != tp6) << std::endl;
// TEST 8
    ft::pair <int, std::string> tp8;
    tp8 = tp6;
    std::cout << tp8.first << std::endl;
    std::cout << tp8.second << std::endl;
    
    return 0;
}