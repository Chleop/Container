/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Maps.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:44:45 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/27 17:46:21 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include <functional>
# include <memory>
# include "pairs.hpp"

# define BLACK  0
# define RED    1

namespace ft
{

template    <class Key,
            class T,
            class Compare = std::less<Key>,
            class Allocator = std::allocator<ft::pair<const Key, T>>>
class map
{
    
public:
/* ************************************************************************** */
/*                               MEMBER TYPES                                 */
/* ************************************************************************** */

    typedef Key                                     key_type;
    typedef T                                       mapped_type;
    typedef ft::pair<const Key, T>                  value_type;
    typedef Compare                                 key_compare;
    typedef Allocator                               allocator_type;
    
    typedef typename Allocator::reference           reference;
    typedef typename Allocator::const_reference     const_reference;
    typedef implementation defined                  iterator; // See 23.1
    typedef implementation defined                  const_iterator; // See 23.1
    typedef implementation defined                  size_type; // See 23.1
    typedef implementation defined                  difference_type;// See 23.1
    typedef typename Allocator::pointer             pointer;
    typedef typename Allocator::const_pointer       const_pointer;
    typedef std::reverse_iterator<iterator>         reverse_iterator;
    typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;

/* ************************************************************************** */
/*                            VALUE-COMPARE CLASS                             */
/* ************************************************************************** */

    class value_compare : public binary_function<value_type,value_type,bool>
    {
        friend class map;
    protected:
        Compare comp;
        value_compare(Compare c) : comp(c) {}
    public:
        bool operator()(const value_type& x, const value_type& y) const 
        {return comp(x.first, y.first);}
    };

/* ************************************************************************** */
/*                        CONSTRUCTORS / DESTRUCTORS                          */
/* ************************************************************************** */

    // Default
    explicit map(const Compare& comp = Compare(), const Allocator& = Allocator())
    {_RedBlackTree = RedBlackTree();}
    // Range
    template <class InputIterator>
    map (InputIterator first,
        InputIterator last,
        const Compare& comp = Compare(),
        const Allocator& = Allocator())
    {}
    // Copy
    map (const map<Key,T,Compare,Allocator>& x)
    {}
    // Destructor
    ~map()
    {}

/* ************************************************************************** */
/*                    ASSIGNMENT OPERATORS AND FUNCTIONS                      */
/* ************************************************************************** */

    map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x);

/* ************************************************************************** */
/*                                 ITERATORS                                  */
/* ************************************************************************** */

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;

/* ************************************************************************** */
/*                                  CAPACITY                                  */
/* ************************************************************************** */

    bool empty() const;
    size_type size() const;
    size_type max_size() const;

/* ************************************************************************** */
/*                               ELEMENTS ACCESS                              */
/* ************************************************************************** */

    T& operator[](const key_type& x)
    {
        return (*((insert(make_pair(x, T()))).first)).second;
    }

/* ************************************************************************** */
/*                                  MODIFIERS                                 */
/* ************************************************************************** */

    ft::pair<iterator, bool> insert(const value_type& x);
    iterator insert(iterator position, const value_type& x);
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last);
    void erase(iterator position);
    size_type erase(const key_type& x);
    void erase(iterator first, iterator last);
    void swap(map<Key,T,Compare,Allocator>&);
    void clear();

/* ************************************************************************** */
/*                                  OBSERVERS                                 */
/* ************************************************************************** */

    key_compare key_comp() const;
    value_compare value_comp() const;

/* ************************************************************************** */
/*                               MAP OPERATIONS                               */
/* ************************************************************************** */

    iterator find(const key_type& x);
    const_iterator find(const key_type& x) const;
    size_type count(const key_type& x) const;
    iterator lower_bound(const key_type& x);
    const_iterator lower_bound(const key_type& x) const;
    iterator upper_bound(const key_type& x);
    const_iterator upper_bound(const key_type& x) const;
    ft::pair<iterator,iterator>
    equal_range(const key_type& x);
    ft::pair<const_iterator,const_iterator>
    equal_range(const key_type& x) const;

/* ************************************************************************** */
/*                              MY SECRET GARDEN                              */
/* ************************************************************************** */

private:
    RedBlackTree    _RedBlackTree;
    size_t          _size;

};

/* ************************************************************************** */
/*                            NON MEMBER OPERATORS                            */
/* ************************************************************************** */

template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator< (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator> (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

/* ************************************************************************** */
/*                          SPECIALIZED ALGORITHMS                            */
/* ************************************************************************** */

template <class Key, class T, class Compare, class Allocator>
void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y)
{x.swap(y);}

}

#endif