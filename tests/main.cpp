/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:42:14 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/11 19:00:35 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int main (void)
{
    try
    {
        test_pairs();
        test_equal();
        // won't test is_integral because the std is c++11, will test within the containers
        // won't test enable_if because the std is c++11, will test within the containers
        test_lex_comp();
        test_stack();
        // test_reverse_iterators();
        test_vectors();
    }
    catch (const std::length_error& le) 
    {
	    std::cerr << "Length error: " << le.what() << std::endl;
    }

    return 0;
}