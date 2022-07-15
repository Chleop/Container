/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators666.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:31:37 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/15 15:06:09 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef ITERATORS_HPP 
// # define ITERATORS_HPP

// // # include "iterators_traits.hpp"

// namespace ft
// {

// template<class _Iterator>
//     struct iterator_traits
//     {
//       typedef typename _Iterator::iterator_category iterator_category;
//       typedef typename _Iterator::value_type        value_type;
//       typedef typename _Iterator::difference_type   difference_type;
//       typedef typename _Iterator::pointer           pointer;
//       typedef typename _Iterator::reference         reference;
//     };

// /// Partial specialization for pointer types.
//     template<class _Tp>
//     struct iterator_traits<_Tp*>
//     {
//       typedef std::random_access_iterator_tag      iterator_category;
//       typedef _Tp                             value_type;
//       typedef ptrdiff_t                       difference_type;
//       typedef _Tp*                            pointer;
//       typedef _Tp&                            reference;
//     };

// /// Partial specialization for const pointer types.
//     template<class _Tp>
//     struct iterator_traits<const _Tp*>
//     {
//       typedef std::random_access_iterator_tag      iterator_category;
//       typedef _Tp                             value_type;
//       typedef ptrdiff_t                       difference_type;
//       typedef const _Tp*                      pointer;
//       typedef const _Tp&                      reference;
//     };

// // If _Iterator has a base returns it otherwise _Iterator is returned
// // untouched
//     template<typename _Iterator, bool _HasBase>
//     struct _Iter_base
//     {
//         typedef _Iterator iterator_type;
//         static iterator_type _S_base(_Iterator __it)
//         { return __it; }
//     };
//     template<typename _Iterator>
//     struct _Iter_base<_Iterator, true>
//     {
//         typedef typename _Iterator::iterator_type iterator_type;
//         static iterator_type _S_base(_Iterator __it)
//         { return __it.base(); }
//     };
    
//   template<class Category, 
//     class T, 
//     class Distance = ptrdiff_t, 
//     class Pointer = T*, 
//     class Reference = T&>
//     struct iterator 
//     {
//       typedef T         value_type;
//       typedef Distance  difference_type;
//       typedef Pointer   pointer;
//       typedef Reference reference;
//       typedef Category  iterator_category;

//     };

//     ///  Marking input iterators.
//     struct input_iterator_tag{};
//     ///  Marking output iterators.
//     struct output_iterator_tag{};
//     /// Forward iterators support a superset of input iterator operations.
//     struct forward_iterator_tag : public input_iterator_tag{};
//     /// Bidirectional iterators support a superset of forward iterator
//     /// operations.
//     struct bidirectional_iterator_tag : public forward_iterator_tag{};
//     /// Random-access iterators support a superset of bidirectional
//     /// iterator operations.
//     struct random_access_iterator_tag : public bidirectional_iterator_tag{};


//     template <class Iterator>
//     class random_access_iterator : public ft::iterator \
//         <typename ft::iterator_traits<Iterator>::iterator_category,
//     typename ft::iterator_traits<Iterator>::value_type,
//     typename ft::iterator_traits<Iterator>::difference_type,
//     typename ft::iterator_traits<Iterator>::pointer,
//     typename ft::iterator_traits<Iterator>::reference>
//     {
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
// 	      typedef typename ft::iterator_traits<Iterator>::value_type         value_type;
// // CONSTRUCTORS / DESTRUCTOR
//         random_access_iterator()                                          {}
//         explicit random_access_iterator(Iterator x):current(x)            {}
//         template <class U> 
//         random_access_iterator(random_access_iterator<U>& u):current(u.current) {}
// // ACCESSOR
//         Iterator base() const   {return current;} // explicit
// // OPERATORS
//         reference operator*() const     {return *current;}
//         pointer operator->() const      {return &(operator*());}
//         random_access_iterator& operator++()  {++current; return *this;}
//         random_access_iterator operator++(int){random_access_iterator tmp = *this; ++current; return tmp;}
//         random_access_iterator& operator--()  {--current; return *this;}
//         random_access_iterator operator--(int){random_access_iterator tmp = *this; --current; return tmp;}

//         random_access_iterator operator+ (difference_type n) const    {return(random_access_iterator(current + n));}
//         random_access_iterator& operator+=(difference_type n)         {current += n; return *this;}
//         random_access_iterator operator- (difference_type n) const    {return(random_access_iterator(current - n));}
//         random_access_iterator& operator-=(difference_type n)         {current -= n; return *this;}
//         reference operator[](difference_type n) const           {return(current[n]);}
//     };
// // NON MEMBER OPERATORS
//     template <class Iterator>
//     bool operator==(const random_access_iterator<Iterator>& x, const random_access_iterator<Iterator>& y)
//     {return (x.base() == y.base());}
//     template <class Iterator>
//     bool operator<(const random_access_iterator<Iterator>& x, const random_access_iterator<Iterator>& y)
//     {return (x.base() < y.base());}
//     template <class Iterator>
//     bool operator!=(const random_access_iterator<Iterator>& x, const random_access_iterator<Iterator>& y)
//     {return (x.base() != y.base());}
//     template <class Iterator>
//     bool operator>(const random_access_iterator<Iterator>& x, const random_access_iterator<Iterator>& y)
//     {return (x.base() > y.base());}
//     template <class Iterator>
//     bool operator>=(const random_access_iterator<Iterator>& x, const random_access_iterator<Iterator>& y)
//     {return (x.base() >= y.base());}
//     template <class Iterator>
//     bool operator<=(const random_access_iterator<Iterator>& x, const random_access_iterator<Iterator>& y)
//     {return (x.base() <= y.base());}
//     template <class Iterator>
//     random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator>& x)
//     {return (x.base() + n);}
//     template <class Iterator>
//     typename random_access_iterator<Iterator>::difference_type operator-(const random_access_iterator<Iterator>& x, const random_access_iterator<Iterator>& y)
//     {return (x.base() - y.base());}

// }

// # endif