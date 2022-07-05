/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:41:57 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/05 18:25:14 by cproesch         ###   ########.fr       */
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
/*   Updated: 2022/06/29 12:41:52 by cproesch         ###   ########.fr       */
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
    // std ci-dessous a modifier lorsque les iterateurs seront ope :
    typedef typename std::vector<T>::iterator           iterator;
    // typedef typename std::const_iterator                const_iterator;
    // typedef std::reverse_iterator<iterator>             reverse_iterator;
    // typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;

private:
    allocator_type  _base;
    size_type       _size;
    size_type       _capacity;
    iterator        _array;
    iterator        _end;

// Called by constructors to check initial size.
    // static size_type
    // _check_init_len(size_type n, const allocator_type& a)
    // {
    //     if (n > std::allocator_traits::_S_max_size(std::allocator_traits::_Tp_alloc_type(a)))
    //         // __throw_length_error(__N("cannot create std::vector larger than max_size()"));
    //     return n;
    // }

public:
// CONSTRUCTORS / DESTRUCTORS
// Default constructor : Constructs an empty container, with no elements.
    explicit vector(const allocator_type& a = allocator_type())
    : _base(a), _size(0), _capacity(0), _array(_base.allocate(_capacity)), _end(_array + _size)
    {
        std::cout << "\033[32m### Using FT  :  \033[37m";
    }
// Fill constructor : Constructs a container with n elements. Each element is a copy of val.
    explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& a = allocator_type())
    : _base(a), _size(n),  _capacity(n), _array(_base.allocate(n)), _end(_array + n)
    {
        std::cout << "\033[32m### Using FT  :  \033[37m";
        // voir s'il ne vaut pas mieux utiliser la fonction fill"
        for (iterator it = _array; it != _end; ++it)
            *it = val;
    }
// Range constructor : Constructs a container with as many elements as the range [first,last),
// with each element constructed from its corresponding element in that range, in the same 
// order.
    template <class InputIterator>
    vector(InputIterator first, InputIterator last, const allocator_type& a = allocator_type())
    : _base(a), _size(last - first),  _capacity(_size), _array(_base.allocate(_size)), _end(_array + _size)
    {
        std::cout << "\033[32m### Using FT  :  \033[37m";
        for (iterator it = _array; it != _end; ++it)
        {
            *it = *(first);
            first++;
        }
    }
// Copy constructor : Constructs a container with a copy of each of the elements in x, 
// in the same order.
    // vector(const vector<T,Allocator>& x);

    // ~vector();

// OPERATEUR ET FONCTIONS D'ASSIGNATION
    // template <class InputIterator>
    // void assign(InputIterator first, InputIterator last)    {erase(begin(), end()); insert(begin(), first, last);}
    // void assign(size_type n, const T& u)                    {erase(begin(), end()); insert(begin(), n, u);}

// ITERATORS
    iterator                begin()         {return _array;}
    // const_iterator          begin() const   {return _array;}
    iterator                end()           {return _end;}
    // const_iterator          end() const     {return _end;}

// CAPACITY
    size_type   size() const        {std::cout << "\033[32m### Using FT  :  \033[37m";return (this->_size);}
    size_type   capacity() const    {std::cout << "\033[32m### Using FT  :  \033[37m";return (this->_capacity);}
    size_type   max_size() const    {std::cout << "\033[32m### Using FT  :  \033[37m";return (_base.max_size());}

// ELEMENT ACCESS

// MODIFIERS
    // iterator        insert(iterator position, const value_type& x)
    // {
    //     // FIRST ALLOCATE MORE MEMORY IF NEEDED
    //     // If current size + 1 is more than the capacity, then we need to allocate more memory
    //     if (this->_size + 1 > this->_capacity)
    //     {
    //         // A COMPLETER!!!!!
    //         this._begin = this->_base.allocate(this->_size + 1);

    //     }
    //     // THEN CONSTRUCT THE OBJECTS
    //     // Increment the size by one
    //     this->_size++;
    //     // Increment the end of the vector by one
    //     this->_end++;
    //     // Copy the objects from position till the end to the next element
    //     for (iterator i = this->_end; i > position; i--)
    //     {
    //         if (i != this->end)
    //             this->_base.destroy(&position[i]);
    //         this->_base.construct(&position[i], position[i - 1]);
    //     }
    //     // Then add the value x at position
    //     for (iterator i = position; i < (position + 1); i++)
    //     {
    //         this->_base.destroy(&position[i]);
    //         this->_base.construct(&position[i], x);
    //     }
    //     return position;
    // }

    // void            insert(iterator position, size_type n, const T& x)
    // {
    //     this._begin = this->_base.allocate(n);
    //     for (unsigned int i = 0; i < n; i++)
    //         this->_base.construct(&position[i], x);
    //     this->_size += n;
    //     return position;
    // }

    // template <class InputIterator>
    // void            insert(iterator position, InputIterator first, InputIterator last)
    // {
    //     this._begin = this->_base.allocate(last - first);
    //     for (unsigned int i = 0; i < (last - first); i++)
    //         this->_base.construct(&position[i], x);
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
