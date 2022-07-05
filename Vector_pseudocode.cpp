/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_pseudocode.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:41:37 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/05 14:20:21 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <vector>      // justtocheck the standard lib
# include <new>         // for bad_alloc


namespace ft 
{
template <class T, class Allocator = std::allocator<T>>
class vector
{

private:
    allocator_type  _base; // = alloc = pointeur vers la memoire allouee pour le vecteur
    pointer         _begin;
    pointer         _end;
    pointer         _array;
    size_type       _size;

public:
// Called by constructors to check initial size.
    static size_type
    _check_init_len(size_type n, const allocator_type& a);
    // Verifies that the desired size is inferior to max_size

// CONSTRUCTORS / DESTRUCTORS
    // vector(void):_base(), _begin(_base), _end(_begin), _array(_base), _size(0){}  pas sure que ce soit necessaire
    // Initializes the size to zero
    explicit vector(const Allocator& = Allocator() a): _base(a), _size(0) {} // lign 497
    explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator() a) // lign 535
    : _base(a), _size(n)
    {
        try
        {
            _check_init_len(n, a);
            std::__uninitialized_fill_n_a (_begin, _size, value, _base);
        }
        catch(std::bad_alloc & ba)
        {
            std::cerr << ba.what() << '\n';
        }
    }
    // template <class InputIterator>
    // vector(InputIterator first, InputIterator last, Const Allocator& = Allocator());
    // vector(const vector<T,Allocator>& x);

    // ~vector();

// OPERATEUR ET FONCTIONS D'ASSIGNATION
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last)    {erase(begin(), end()); insert(begin(), first, last);}
    void assign(size_type n, const T& u)                    {erase(begin(), end()); insert(begin(), n, u);}

// ITERATORS

// CAPACITY
    size_type   size() const {return (this->_size);}

// ELEMENT ACCESS

// MODIFIERS
    iterator        insert(iterator position, const T& x)
    {
        this->_size = ;
    }

    void            insert(iterator position, size_type n, const T& x)
    {
        this->_size = ;
        _M_fill_insert(__position, __n, __x);
    }

    template <class InputIterator>
    void            insert(iterator position, InputIterator first, InputIterator last)
    {
        this->_size = ;
    }

    iterator        erase(iterator position)
    {
        this->_size = ;
    }
    iterator        erase(iterator first, iterator last)
    {
        this->_size = ;
    }

    void            clear(void)
    {
        if (size_type __n = _end - _begin)
          {
            std::_Destroy(_begin, _end, Allocator());
            _end = _begin;
          }
    };

};
}