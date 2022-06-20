/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:05:13 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/17 19:12:25 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

template
class VectorIterator<class T,class Allocator = std::allocator<T>>
{
public:
    typedef T               value_type;
    typedef value_type*     iterator;
    typedef const iterator  const_iterator;
    
    VectorIterator(void){}
    VectorIterator(VectorIterator it):_iter(it){}
    ~VectorIterator(){}
    
    VectorIterator &operator=(const VectorIterator rhs){_iter = rhs._iter; return *this;}
    
    VectorIterator &operator++(){this->_iter++; return *this}
    VectorIterator operator++(){VectorIterator temp(*this); this->_iter++; return temp;}
    VectorIterator &operator--(){this->_iter--; return *this}
    VectorIterator operator--(){VectorIterator temp(*this); this->_iter--; return temp;}
    // bool             operator==(){}
    // bool             operator!=(){}
    // VectorIterator*  operator*(){}   PAS SURE DU TYPE
    // VectorIterator   &operator->(){} PAS SURE DU TYPE
    // VectorIterator   operator+(){}
    // VectorIterator   operator-(){}
    // bool             operator<(){}
    // bool             operator>(){}
    // bool             operator<=(){}
    // bool             operator>=(){}
    // VectorIterator   operator+=(){}
    // VectorIterator   operator-=(){}
    // T &              operator[](){}  PAS SURE DU TYPE

    iterator _iter;

private:

};

#endif
