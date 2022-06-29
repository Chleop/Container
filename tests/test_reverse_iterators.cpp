/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_iterators.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:14:00 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/29 15:51:25 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_reverse_iterators (void)
{
// TEST 1
    std::vector<int> v {0, 1, 2, 3};
    REV_ITER<std::vector<int>::iterator> ri1 { REV_ITER<std::vector<int>::iterator> {v.begin()} };
    REV_ITER<std::vector<int>::iterator> ri2 { REV_ITER<std::vector<int>::iterator> {v.end()} };
    std::cout << (ri2 - ri1) << ' ' << std::endl;
    std::cout << (ri1 - ri2) << std::endl;
// TEST 2


}