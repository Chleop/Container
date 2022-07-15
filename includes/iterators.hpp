/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:31:37 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/15 10:36:33 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP 
# define ITERATOR_HPP

namespace ft
{

    template<class Category, 
    class T, 
    class Distance = ptrdiff_t, 
    class Pointer = T*, 
    class Reference = T&>
    struct iterator 
    {
      typedef T         value_type;
      typedef Distance  difference_type;
      typedef Pointer   pointer;
      typedef Reference reference;
      typedef Category  iterator_category;

    };

    ///  Marking input iterators.
    struct input_iterator_tag{};
    ///  Marking output iterators.
    struct output_iterator_tag{};
    /// Forward iterators support a superset of input iterator operations.
    struct forward_iterator_tag : public input_iterator_tag{};
    /// Bidirectional iterators support a superset of forward iterator
    /// operations.
    struct bidirectional_iterator_tag : public forward_iterator_tag{};
    /// Random-access iterators support a superset of bidirectional
    /// iterator operations.
    struct random_access_iterator_tag : public bidirectional_iterator_tag{};

}

# endif