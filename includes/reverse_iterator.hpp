/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:38:42 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/29 12:41:17 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
// CLASS ITERATOR
    template <class Iterator>
    class reverse_iterator
    : public iterator   <typename std::iterator_traits<Iterator>::iterator_category,
                        typename std::iterator_traits<Iterator>::value_type,
                        typename std::iterator_traits<Iterator>::difference_type,
                        typename std::iterator_traits<Iterator>::pointer,
                        typename std::iterator_traits<Iterator>::reference>
    {
    protected:
// 
        Iterator current;

    public:
// MEMBER TYPES
        typedef Iterator                                                    iterator_type;
        typedef typename std::iterator_traits<Iterator>::difference_type    difference_type;
        typedef typename std::iterator_traits<Iterator>::reference          reference;
        typedef typename std::iterator_traits<Iterator>::pointer            pointer;
        typedef typename std::iterator_traits<Iter>::iterator_category      iterator_category;
	    typedef typename std::iterator_traits<Iter>::value_type             value_type;
// CONSTRUCTORS / DESTRUCTOR
        reverse_iterator();
        explicit reverse_iterator(Iterator x):current(x){}
        template <class U> reverse_iterator(const reverse_iterator<U>& u):current(u.current){}
// ACCESSOR
        Iterator base() const{return current;} // explicit
// OPERATORS
        reference operator*() const     {iterator_type tmp = current; return *--tmp;}
        pointer operator->() const      {return &(opertor*());}
        reverse_iterator& operator++()  {--current; return *this;}
        reverse_iterator operator++(int){reverse_iterator tmp = *this; --current; return tmp;}
        reverse_iterator& operator--()  {++current; return *this;}
        reverse_iterator operator--(int){reverse_iterator tmp = *this; ++current; return tmp;}

        reverse_iterator operator+ (difference_type n) const    {reverse_iterator(current - n);}
        reverse_iterator& operator+=(difference_type n)         {current -= n; return *this;}
        reverse_iterator operator- (difference_type n) const    {reverse_iterator(current + n);}
        reverse_iterator& operator-=(difference_type n)         {current += n; return *this;}
        reference operator[](difference_type n) const           {current[-n - 1];}
    };
// NON MEMBER FUNCTIONS
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x);
}

#endif