/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:42:14 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/24 12:05:31 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int main (void)
{
    test_pairs();
    test_equal();
    // won't test is_integral because the std is c++11, will test within the containers
    
    return 0;
}