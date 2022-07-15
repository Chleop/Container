/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:50:53 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/15 18:36:29 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP 
# define ITERATORS_HPP

namespace ft
{

template<class T>
struct iterator 
{

public:
// MEMBER TYPES
    typedef T           value_type;
    typedef ptrdiff_t   difference_type;
    typedef T&          reference;
    typedef T*          pointer;
    // typedef Category  iterator_category;
// CONSTRUCTORS / DESTRUCTOR
    iterator()                                  {}
    explicit iterator(value_type x):current(&x)   {}
    template <class U> 
    iterator(iterator<U>& u):current(u.current) {}
// ACCESSOR
    value_type base() const   {return *current;} // explicit
// OPERATORS
    reference operator*() const     {return *current;}
    pointer operator->() const      {return current;}
    iterator& operator++()          {++current; return *this;}
    iterator operator++(int)        {iterator tmp = *this; ++current; return tmp;}
    iterator& operator--()          {--current; return *this;}
    iterator operator--(int)        {iterator tmp = *this; --current; return tmp;}

    iterator operator+ (difference_type n) const    {return(iterator(current + n));}
    iterator& operator+=(difference_type n)         {current += n; return *this;}
    iterator operator- (difference_type n) const    {return(iterator(current - n));}
    iterator& operator-=(difference_type n)         {current -= n; return *this;}
    reference operator[](difference_type n) const   {return(current[n]);}

protected:
// MEMBER OBJECT
    pointer current;
};

// NON MEMBER OPERATORS
template <class value_type>
bool operator==(const iterator<value_type>& x, const iterator<value_type>& y)
{return (x.base() == y.base());}
template <class value_type>
bool operator<(const iterator<value_type>& x, const iterator<value_type>& y)
{return (x.base() < y.base());}
template <class value_type>
bool operator!=(const iterator<value_type>& x, const iterator<value_type>& y)
{return (x.base() != y.base());}
template <class value_type>
bool operator>(const iterator<value_type>& x, const iterator<value_type>& y)
{return (x.base() > y.base());}
template <class value_type>
bool operator>=(const iterator<value_type>& x, const iterator<value_type>& y)
{return (x.base() >= y.base());}
template <class value_type>
bool operator<=(const iterator<value_type>& x, const iterator<value_type>& y)
{return (x.base() <= y.base());}
template <class value_type>
iterator<value_type> operator+(typename iterator<value_type>::difference_type n, const iterator<value_type>& x)
{return (x.base() + n);}
template <class value_type>
typename iterator<value_type>::difference_type operator-(const iterator<value_type>& x, const iterator<value_type>& y)
{return (x.base() - y.base());}

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
struct iterator_tag : public bidirectional_iterator_tag{};

}

#endif