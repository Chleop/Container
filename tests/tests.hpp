/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:11:23 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/22 15:51:38 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#ifndef LIB
# define LIB_PAIR ft::pair
# define LIB_MAKE_PAIR ft::make_pair
#else
# define LIB_PAIR std::pair
# define LIB_MAKE_PAIR std::make_pair
#endif

# include <iostream> 
# include <utility>
# include "../includes/pairs.hpp"

void test_pairs(void);

#endif