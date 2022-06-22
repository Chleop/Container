/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:04:31 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/17 19:13:08 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

// Ne pas oublier de proteger les includes 
// "Vous devez pouvoir utiliser vos fichiers d’en-tête séparément les uns des autres.
// C’est pourquoi ils devront inclure toutes les dépendances qui leur seront nécessaires. 
// Cependant, vous devez éviter le problème de la double inclusion en les protégeant
// avec des include guards"

# include <memory>
# include "VectorIterator.hpp"

template<class T,class Allocator = std::allocator<T>>
class vector
{
public:
// MEMBER TYPES

    typedef std::size_t                                 size_type;
    typedef std::ptrdiff_t                              difference_type;
    typedef T                                           value_type;
    typedef Allocator                                   allocator_type;
    typedef typename VectorIterator::iterator           iterator;
    typedef typename VectorIterator::const_iterator     const_iterator;
    typedef typename Allocator::reference               reference;
    typedef typename Allocator::const_reference         const_reference;
    typedef typename Allocator::pointer                 pointer;
    typedef typename Allocator::const_pointer           const_pointer;
    typedef std::reverse_iterator<iterator>             reverse_iterator;
    typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;

// CONSTRUCTORS / DESTRUCTORS

    // explicit vector(const Allocator& = Allocator());
    // explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator());
    // template <class InputIterator>
    // vector(InputIterator first, InputIterator last, Const Allocator& = Allocator());
    // vector(const vector<T,Allocator>& x);
    // ~vector();

    // vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last){erase(begin(), end()); insert(begin(), first, last);}
    void assign(size_type n, const T& u){erase(begin(), end()); insert(begin(), n, t);}
    // allocator_type get_allocator() const;

// ITERATORS
    // iterator                begin();
    // const_iterator          begin() const;
    // iterator                end();
    // const_iterator          end() const;
    // reverse_iterator        rbegin();
    // const_reverse_iterator  rbegin() const;
    // reverse_iterator        rend();
    // const_reverse_iterator  rend() const;

// CAPACITY
    // size_type   size() const;
    // size_type   max_size() const;
    // void        resize(size_type sz, T c = T());
    // size_type   capacity() const;
    // bool        empty() const;
    // void        reserve(size_type n);

// ELEMENT ACCESS
    // reference           operator[](size_type n);
    // const_reference     operator[](size_type n) const;
    // const_reference     at(size_type n) const;
    // reference           at(size_type n);
    // reference           front();
    // const_reference     front() const;
    // reference           back();
    // const_reference     back() const;

// MODIFIERS
    // void            push_back(const T& x);
    // void            pop_back();
    // iterator        insert(iterator position, const T& x);
    // void            insert(iterator position, size_type n, const T& x);
    // template <class InputIterator>
    // void            insert(iterator position, InputIterator first, InputIterator last);
    // iterator        erase(iterator position);
    // iterator        erase(iterator first, iterator last);
    void            swap(vector<T,Allocator>&){x.swap(y);}
    // void            clear();

// OPERATORS
    // template <class T, class Allocator>
    // bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    // template <class T, class Allocator>
    // bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    // template <class T, class Allocator>
    // bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    // template <class T, class Allocator>
    // bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    // template <class T, class Allocator>
    // bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    // template <class T, class Allocator>
    // bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    // template <class T, class Allocator>
    // void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);    
    
};

#endif
