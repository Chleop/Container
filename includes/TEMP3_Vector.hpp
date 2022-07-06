/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEMP3_Vector.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:41:57 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/06 12:29:12 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <vector>


namespace ft 
{
template <class T, class Allocator = std::allocator<T>>
class vector
{

public:
// MEMBER TYPES

    typedef std::size_t                                 size_type;
    typedef std::ptrdiff_t                              difference_type;
    typedef T                                           value_type;
    typedef Allocator                                   allocator_type;
    typedef typename Allocator::reference               reference;
    typedef typename Allocator::const_reference         const_reference;
    typedef typename Allocator::pointer                 pointer;
    typedef typename Allocator::const_pointer           const_pointer;
    typedef typename std::vector<T>::iterator           iterator;
    typedef typename std::vector<T>::const_iterator     const_iterator;

private:
    allocator_type  _alloc;
    size_type       _size;
    size_type       _capacity;
    iterator        _array;

public:
// CONSTRUCTORS / DESTRUCTORS
// Default
    explicit vector(const allocator_type& a = allocator_type()):
    _alloc(a), _size(0), _capacity(0)
    {}
// Fill
    explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& a = allocator_type()):
    _alloc(a), _size(n),  _capacity(n), _array(_alloc.allocate(n))
    {
        for (iterator it = _array; it != _end; ++it)
            *it = val;
    }
// Range
    // template <class InputIterator>
    // vector(InputIterator first, InputIterator last, const allocator_type& a = allocator_type()):
    // _alloc(a), _size(last - first),  _capacity(_size), _array(_alloc.allocate(_size)), _end(_array + _size)
    // {
    //     for (iterator it = _array; it != _end; ++it)
    //     {
    //         *it = *(first);
    //         first++;
    //     }
    // }
// Copy
    // vector(const vector<T,Allocator>& x)
    // {
    //     *this = vector(x.begin(), x.end());
    // }

    // ~vector()
    {
    }

// OPERATEUR ET FONCTIONS D'ASSIGNATION
    // template <class InputIterator>
    // void assign(InputIterator first, InputIterator last)    {erase(begin(), end()); insert(begin(), first, last);}
    // void assign(size_type n, const T& u)                    {erase(begin(), end()); insert(begin(), n, u);}

// ITERATORS
    iterator                begin()         {return _array;}
    // const_iterator          begin() const   {return _array;}
    iterator                end()           {return (_array + _size);}
    // const_iterator          end() const     {return _end;}

// CAPACITY
    size_type   size() const        {std::cout << "\033[32m### Using FT  :  \033[37m";return (this->_size);}
    size_type   capacity() const    {std::cout << "\033[32m### Using FT  :  \033[37m";return (this->_capacity);}
    size_type   max_size() const    {std::cout << "\033[32m### Using FT  :  \033[37m";return (_alloc.max_size());}

// ELEMENT ACCESS

// MODIFIERS
    iterator        insert(iterator position, const value_type& x) //line 530
    {
        // FIRST ALLOCATE MORE MEMORY IF NEEDED
        // If current size + 1 is more than the capacity, then we need to allocate more memory
        if (this->_size + 1 > this->_capacity)
        {
            // A COMPLETER!!!!!
            this._begin = this->_alloc.allocate(this->_size + 1);

        }
        // THEN CONSTRUCT THE OBJECTS
        // Increment the size by one
        this->_size++;
        // Increment the end of the vector by one
        this->_end++;
        // Copy the objects from position till the end to the next element
        for (iterator i = this->_end; i > position; i--)
        {
            if (i != this->end)
                this->_alloc.destroy(&position[i]);
            this->_alloc.construct(&position[i], position[i - 1]);
        }
        // Then add the value x at position
        for (iterator i = position; i < (position + 1); i++)
        {
            this->_alloc.destroy(&position[i]);
            this->_alloc.construct(&position[i], x);
        }
        return position;
    }

    // void            insert(iterator position, size_type n, const T& x)
    // {
    //     this._begin = this->_alloc.allocate(n);
    //     for (unsigned int i = 0; i < n; i++)
    //         this->_alloc.construct(&position[i], x);
    //     this->_size += n;
    //     return position;
    // }

    // template <class InputIterator>
    // void            insert(iterator position, InputIterator first, InputIterator last)
    // {
    //     this._begin = this->_alloc.allocate(last - first);
    //     for (unsigned int i = 0; i < (last - first); i++)
    //         this->_alloc.construct(&position[i], x);
    //     this->_size += (last - first);
    //     return position;
    // }

    // iterator        erase(iterator position)
    // {
    //     this->_size = ;
    // }
    // iterator        erase(iterator first, iterator last)
    // {
    //     this->_size = ;
    // }

    // void            clear(void)
    // {
    //     if (size_type __n = _end - _begin)
    //       {
    //         std::_Destroy(_begin, _end, Allocator());
    //         _end = _begin;
    //       }
    // };

};
}

#endif
