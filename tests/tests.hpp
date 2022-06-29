/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:11:23 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/29 16:29:27 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#ifndef LIB
# define PAIR ft::pair
# define MAKE_PAIR ft::make_pair
# define EQUAL ft::equal
# define STACK ft::stack
# define REV_ITER ft::reverse_iterator
#else
# define PAIR std::pair
# define MAKE_PAIR std::make_pair
# define EQUAL std::equal
# define STACK std::stack
# define REV_ITER std::reverse_iterator
#endif

# include <iostream> 
# include <utility>
# include <vector>
# include "../includes/pairs.hpp"
# include "../includes/equal.hpp"
# include "../includes/stack.hpp"
# include "../includes/reverse_iterator.hpp"

void test_pairs(void);
void test_equal(void);
void test_stack(void);
void test_reverse_iterators (void);

#endif