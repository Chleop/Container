/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:38:42 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/15 18:07:02 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterators.hpp"

// [Example: To implement a generic reverse function, a C++ program can do the following:
// template <class BidirectionalIterator>
// void reverse(BidirectionalIterator first, BidirectionalIterator last) 
// {
//     typename iterator_traits<BidirectionalIterator>::difference_type n = distance(first, last);
//     --n;
//     while(n > 0)
//     {
//         typename iterator_traits<BidirectionalIterator>::value_type tmp = *first;
//         *first++ = *--last;
//         *last = tmp;
//         n -= 2;
//     }
// }
// —end example]


namespace ft
{
// CLASS REVERSE ITERATOR
    template <class Iterator>
    class reverse_iterator : public ft::iterator<Iterator>
    {
    protected:
// MEMBER OBJECT
        Iterator current;

    public:
// MEMBER TYPES
        typedef ptrdiff_t   difference_type;
        typedef Iterator&   reference;
        typedef Iterator*   pointer;
	    typedef Iterator    value_type;
// CONSTRUCTORS / DESTRUCTOR
        reverse_iterator()                                          {}
        explicit reverse_iterator(Iterator x):current(x)            {}
        template <class U> 
        reverse_iterator(reverse_iterator<U>& u):current(u.current) {}
// ACCESSOR
        Iterator base() const   {return current;} // explicit
// OPERATORS
        reference operator*() const     {Iterator tmp = current; return (*--tmp);}
        pointer operator->() const      {return &(operator*());}
        reverse_iterator& operator++()  {--current; return *this;}
        reverse_iterator operator++(int){reverse_iterator tmp = *this; --current; return tmp;}
        reverse_iterator& operator--()  {++current; return *this;}
        reverse_iterator operator--(int){reverse_iterator tmp = *this; ++current; return tmp;}

        reverse_iterator operator+ (difference_type n) const    {return(reverse_iterator(current - n));}
        reverse_iterator& operator+=(difference_type n)         {current -= n; return *this;}
        reverse_iterator operator- (difference_type n) const    {return(reverse_iterator(current + n));}
        reverse_iterator& operator-=(difference_type n)         {current += n; return *this;}
        reference operator[](difference_type n) const           {return(current[- n - 1]);}
    };
// NON MEMBER OPERATORS
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {return (x.base() == y.base());}
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {return (x.base() > y.base());}
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {return (x.base() != y.base());}
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {return (x.base() < y.base());}
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {return (x.base() <= y.base());}
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {return (x.base() >= y.base());}
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
    {return (x.base() - n);}
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {return (y.base() - x.base());}

// CLASS CONST REVERSE ITERATOR
    template <class Iterator>
    class const_reverse_iterator : public reverse_iterator <Iterator>
    {
//     protected:
// // MEMBER OBJECT
//         Iterator current;

//     public:
// // MEMBER TYPES
//         typedef Iterator                                                   iterator_type;
//         typedef typename ft::iterator_traits<Iterator>::difference_type    difference_type;
//         typedef typename ft::iterator_traits<Iterator>::reference          reference;
//         typedef typename ft::iterator_traits<Iterator>::pointer            pointer;
//         typedef typename ft::iterator_traits<Iterator>::iterator_category  iterator_category;
// 	    typedef typename ft::iterator_traits<Iterator>::value_type         value_type;
// // CONSTRUCTORS / DESTRUCTOR
//         const_reverse_iterator()                                          {}
//         explicit const_reverse_iterator(Iterator x):current(x)            {}
//         template <class U> 
//         const_reverse_iterator(const_reverse_iterator<U>& u):current(u.current) {}
// // ACCESSOR
//         // Iterator base() const   {return current;} // explicit
// // OPERATORS
//         // reference operator*() const     {Iterator tmp = current; return *--tmp;}
//         // pointer operator->() const      {return &(operator*());}
//         const_reverse_iterator& operator++()  {--current; return *this;}
//         const_reverse_iterator operator++(int){const_reverse_iterator tmp = *this; --current; return tmp;}
//         const_reverse_iterator& operator--()  {++current; return *this;}
//         const_reverse_iterator operator--(int){const_reverse_iterator tmp = *this; ++current; return tmp;}

//         const_reverse_iterator operator+ (difference_type n) const    {return(const_reverse_iterator(current - n));}
//         const_reverse_iterator& operator+=(difference_type n)         {current -= n; return *this;}
//         const_reverse_iterator operator- (difference_type n) const    {return(const_reverse_iterator(current + n));}
//         const_reverse_iterator& operator-=(difference_type n)         {current += n; return *this;}
//         // reference operator[](difference_type n) const           {return(current[- n - 1]);}
    };
}

#endif