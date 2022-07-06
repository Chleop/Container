/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_pseudocode.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:41:37 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/06 11:07:47 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:04:31 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/05 14:20:14 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft 
{
template <class T, class Allocator = std::allocator<T>>
class vector
{
// MEMBER TYPES

    typedef std::size_t                                 size_type;
    // equivalent to an unsigned int
    typedef std::ptrdiff_t                              difference_type;
    // a type that can be used to identify distance between iterators
    typedef T                                           value_type;
    // the type of the values that can be obtained by dereferencing the iterator. 
    // This type is void for output iterators.
    typedef Allocator                                   allocator_type;
    typedef typename std::iterator                      iterator;
    typedef typename std::const_iterator                const_iterator;
    typedef typename Allocator::reference               reference;
    // defines a reference to the type iterated over (value_type)
    typedef typename Allocator::const_reference         const_reference;
    typedef typename Allocator::pointer                 pointer;
    // defines a pointer to the type iterated over (value_type)
    typedef typename Allocator::const_pointer           const_pointer;
    typedef std::reverse_iterator<iterator>             reverse_iterator;
    typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;

public:
// CONSTRUCTORS / DESTRUCTORS
    explicit vector(const Allocator& = Allocator() a);
    explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator() a);
    template <class InputIterator>
    vector(InputIterator first, InputIterator last, Const Allocator& = Allocator());
    vector(const vector<T,Allocator>& x);

    ~vector();

// OPERATEUR ET FONCTIONS D'ASSIGNATION
    vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last){erase(begin(), end()); insert(begin(), first, last);}
    void assign(size_type n, const T& u){erase(begin(), end()); insert(begin(), n, t);}
    allocator_type get_allocator() const;

// ITERATORS
    iterator                begin();
    const_iterator          begin() const;
    iterator                end();
    const_iterator          end() const;
    reverse_iterator        rbegin();
    const_reverse_iterator  rbegin() const;
    reverse_iterator        rend();
    const_reverse_iterator  rend() const;

// CAPACITY
    size_type   size() const;
    size_type   max_size() const;
    void        resize(size_type sz, T c = T());
    size_type   capacity() const;
    bool        empty() const;
    void        reserve(size_type n);

// ELEMENT ACCESS
    reference           operator[](size_type n);
    const_reference     operator[](size_type n) const;
    const_reference     at(size_type n) const;
    reference           at(size_type n);
    reference           front();
    const_reference     front() const;
    reference           back();
    const_reference     back() const;

// MODIFIERS
    void            push_back(const T& x);
    void            pop_back();
    iterator        insert(iterator position, const T& x);
    // if size + 1 > capacity
    // 
    void            insert(iterator position, size_type n, const T& x);
    template <class InputIterator>
    void            insert(iterator position, InputIterator first, InputIterator last);

    iterator        erase(iterator position);
    iterator        erase(iterator first, iterator last);
    void            swap(vector<T,Allocator>&){x.swap(y);}
    void            clear(void);

// OPERATORS
    template <class T, class Allocator>
    bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    template <class T, class Allocator>
    bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    template <class T, class Allocator>
    bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    template <class T, class Allocator>
    bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    template <class T, class Allocator>
    bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    template <class T, class Allocator>
    bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    template <class T, class Allocator>
    void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);    
    
};
}

#endif
