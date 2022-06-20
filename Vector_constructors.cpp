/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_constructors.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:56:50 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/17 16:04:53 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"


void Vector::assign(InputIterator first, InputIterator last)
{
    erase(begin(), end());
    insert(begin(), first, last);
    return;
}

void Vector::assign(size_type n, const T& u)
{
    erase(begin(), end());
    insert(begin(), n, t);
    return;
}

