/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_equal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:39:33 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/23 14:17:46 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/equal.hpp"

#include <bits/stdc++.h>

bool pred(int i, int j)
{
    return (i != j);
}

int main(void)
{
    int v1[] = { 10, 20, 30, 40, 50 };
    std::vector<int> vector_1 (v1, v1 + sizeof(v1) / sizeof(int) );
 
    if ( std::equal (vector_1.begin(), vector_1.end(), v1) )
        std::cout << "The contents of both sequences are equal.\n";
    else
        std::cout << "The contents of both sequences differ.\n";
    if ( ft::equal (vector_1.begin(), vector_1.end(), v1) )
        std::cout << "The contents of both sequences are equal.\n";
    else
        std::cout << "The contents of both sequences differ.\n";

    if ( std::equal (vector_1.begin(), vector_1.end(), v1, pred) )
        std::cout << "The contents of both sequences are equal.\n";
    else
        std::cout << "The contents of both sequences differ.\n";
    if ( ft::equal (vector_1.begin(), vector_1.end(), v1, pred) )
        std::cout << "The contents of both sequences are equal.\n";
    else
        std::cout << "The contents of both sequences differ.\n";

    return 0;
}
