// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   iterators.hpp                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/07/15 14:50:53 by cproesch          #+#    #+#             */
// /*   Updated: 2022/07/16 16:51:57 by cproesch         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef ITERATORS_HPP 
// # define ITERATORS_HPP

// namespace ft
// {

// template<class T>
// struct iterator 
// {

// public:
// // MEMBER TYPES
//     typedef T                           value_type;
//     typedef ptrdiff_t                   difference_type;
//     typedef T&                          reference;
//     typedef T*                          pointer;
//     typedef random_access_iterator_tag  iterator_category;
//     // typedef const T*                   const_iterator;

// // CONSTRUCTORS / DESTRUCTOR
//     iterator(){}
//     explicit iterator(value_type x):current(&x){}
//     iterator(pointer u):current(u){}
//     // iterator(iterator<T>& u) {if(*this != u) *this = u;}
//     // iterator(const_iterator & u) {if(*this != u) *this = u;}
// // ACCESSOR
//     value_type base() const   {return *current;} // explicit
// // OPERATORS
//     iterator& operator=(iterator<value_type>& x)  {current = x.current; return *this;}
//     reference operator*() const     {return *current;}
//     pointer operator->() const      {return current;}
//     iterator& operator++()          {++current; return *this;}
//     iterator operator++(int)        {iterator tmp = *this; ++current; return tmp;}
//     iterator& operator--()          {--current; return *this;}
//     iterator operator--(int)        {iterator tmp = *this; --current; return tmp;}

//     iterator operator+ (difference_type n) const    {return(iterator(current + n));}
//     iterator& operator+=(difference_type n)         {current += n; return *this;}
//     iterator operator- (difference_type n) const    {return(iterator(current - n));}
//     iterator& operator-=(difference_type n)         {current -= n; return *this;}
//     reference operator[](difference_type n) const   {return(current[n]);}

// // protected:
// // MEMBER OBJECT
//     pointer current;
// };

// // NON MEMBER OPERATORS
// template <class T>
// bool operator==(const iterator<T>& x, const iterator<T>& y)
// {return (x.current == y.current);}
// template <class T>
// bool operator<(const iterator<T>& x, const iterator<T>& y)
// {return (x.current < y.current);}
// template <class T>
// bool operator!=(const iterator<T>& x, const iterator<T>& y)
// {return (x.current != y.current);}
// template <class T>
// bool operator>(const iterator<T>& x, const iterator<T>& y)
// {return (x.current > y.current);}
// template <class T>
// bool operator>=(const iterator<T>& x, const iterator<T>& y)
// {return (x.current >= y.current);}
// template <class T>
// bool operator<=(const iterator<T>& x, const iterator<T>& y)
// {return (x.current <= y.current);}
// template <class T>
// iterator<T> operator+(typename iterator<T>::difference_type n, const iterator<T>& x)
// {return (x.current + n);}
// template <class T>
// typename iterator<T>::difference_type operator-(const iterator<T>& x, const iterator<T>& y)
// {return (x.current - y.current);}

// template<class T>
// struct const_iterator  : public iterator <T>
// {

// public:
// // MEMBER TYPES
//     typedef T           value_type;
//     typedef ptrdiff_t   difference_type;
//     typedef T&          reference;
//     typedef T*          pointer;

// // CONSTRUCTORS / DESTRUCTOR
//     const_iterator()                                  {}
//     explicit const_iterator(value_type x):current(&x)   {}
//     const_iterator(pointer u):current(u) {}
//     // const_iterator(const_iterator<T>& u) {if(*this != u) *this = u;}
//     // const_iterator(iterator<T>& u) {if(*this != u) *this = u;}
// // ACCESSOR
//     value_type base() const   {return *current;} // explicit
// // OPERATORS
//     const_iterator& operator=(iterator<value_type>& x)  {current = x.current; return *this;}
//     reference operator*() const     {return *current;}
//     pointer operator->() const      {return current;}
//     const_iterator& operator++()          {++current; return *this;}
//     const_iterator operator++(int)        {const_iterator tmp = *this; ++current; return tmp;}
//     const_iterator& operator--()          {--current; return *this;}
//     const_iterator operator--(int)        {const_iterator tmp = *this; --current; return tmp;}

//     const_iterator operator+ (difference_type n) const    {return(const_iterator(current + n));}
//     const_iterator& operator+=(difference_type n)         {current += n; return *this;}
//     const_iterator operator- (difference_type n) const    {return(const_iterator(current - n));}
//     const_iterator& operator-=(difference_type n)         {current -= n; return *this;}
//     reference operator[](difference_type n) const   {return(current[n]);}

// // protected:
// // MEMBER OBJECT
//     pointer current;
// };

// }

// #endif