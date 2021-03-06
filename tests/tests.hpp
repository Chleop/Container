/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:11:23 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/11 19:00:34 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#ifndef LIB
# define PAIR       ft::pair
# define MAKE_PAIR  ft::make_pair
# define EQUAL      ft::equal
# define STACK      ft::stack
# define REV_ITER   ft::reverse_iterator
# define VECTOR     ft::vector
# define LEX        ft::lexicographical_compare
#else
# define PAIR       std::pair
# define MAKE_PAIR  std::make_pair
# define EQUAL      std::equal
# define STACK      std::stack
# define REV_ITER   std::reverse_iterator
# define VECTOR     std::vector
# define LEX        std::lexicographical_compare
#endif

# include <iostream> 
# include <utility>
# include <vector>
# include "../includes/pairs.hpp"
# include "../includes/equal.hpp"
# include "../includes/enable_if.hpp"
# include "../includes/is_integral.hpp"
# include "../includes/lex_compare.hpp"
# include "../includes/stack.hpp"
// # include "../includes/reverse_iterator.hpp"
# include "../includes/Vector.hpp"

void test_pairs(void);
void test_equal(void);
void test_stack(void);
// void test_reverse_iterators(void);
void test_lex_comp(void);
void test_vectors(void);

#endif