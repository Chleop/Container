/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:42:09 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/21 16:56:49 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
    
template<class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    while(first1 < last1)
    {
        if (*first1 == *(first2 + (first1 - first1)), std::pred(*first1, *(first2 + (first1 - first1))) != false)
            first1++;
        else
            return false;
    }
    return true;
}

// template<class InputIterator1, class InputIterator2, class BinaryPredicate>
// bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
// {
    
// }

}

#endif
