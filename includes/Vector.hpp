/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:04:31 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/07 17:16:25 by cproesch         ###   ########.fr       */
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

public:
// MEMBER TYPES
    typedef std::size_t                                     size_type;
    typedef std::ptrdiff_t                                  difference_type;
    typedef T                                               value_type;
    typedef Allocator                                       allocator_type;
    // std ci-dessous a modifier lorsque les iterateurs seront ope :
    typedef typename std::vector<T>::iterator               iterator;
    typedef typename std::vector<T>::const_iterator         const_iterator;
    typedef typename std::vector<T>::reverse_iterator       reverse_iterator;
    typedef typename std::vector<T>::const_reverse_iterator const_reverse_iterator;
    typedef typename allocator_type::reference              reference;
    typedef typename allocator_type::const_reference        const_reference;
    typedef typename allocator_type::pointer                pointer;
    typedef typename allocator_type::const_pointer          const_pointer;

// CONSTRUCTORS / DESTRUCTORS
// Default
    explicit vector(const allocator_type& a = allocator_type()):
        _alloc(a), 
        _size(0), 
        _capacity(0)
        {}
// Fill
    explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& a = allocator_type()):
        _alloc(a), 
        _size(n),  
        _capacity(n), 
        _array(_alloc.allocate(n))
        {std::fill(this->begin(), this->end(), val);}
// Range
    template <class InputIterator, class = typename ft::enable_if<ft::is_integral<InputIterator>::value == false>::type>
    vector(InputIterator first, InputIterator last, const allocator_type& a = allocator_type()):
        _alloc(a), 
        _size(last - first),  
        _capacity(_size), 
        _array(_alloc.allocate(_size))
        {std::copy(first, last, this->begin());}
// Copy
    vector(const vector<T,Allocator>& x):
        _alloc(x._alloc), 
        _size(0), 
        _capacity(0)
        {*this = x;}
// Destructor
    ~vector()
        {clear();if (_capacity > 0)_alloc.deallocate(&(*_array), _capacity);}

// OPERATEUR ET FONCTIONS D'ASSIGNATION
    vector<T,Allocator>&    operator=(const vector<T,Allocator>& x)
                            {if (_capacity < x._size)
                                {if (_capacity > 0)
                                    _alloc.deallocate(&(*_array), _capacity);
                                _array = _alloc.allocate(x._size);
                                _capacity = x._size;}
                            _size = x._size;
                            std::copy(x.begin(), x.end(), this->begin());
                            return *this;}
    template <class InputIterator>
    void            assign(InputIterator first, InputIterator last)
                    {erase(begin(), end()); insert(begin(), first, last);}
    void            assign(size_type n, const T& u)
                    {erase(begin(), end()); insert(begin(), n, u);}
    allocator_type  get_allocator() const
                    {return _alloc;}

// ITERATORS
// ----------------------------->TO DO :voir s'il faut throw une erreur par exemple lorsqu'on fait un 
// begin() sur un vecteur non initialise (le std fait un segfault)
    iterator                begin()         {return iterator(_array);}
    const_iterator          begin() const   {return const_iterator(_array);}
    iterator                end()           {return iterator(_array + _size);}
    const_iterator          end() const     {return const_iterator(_array + _size);}
    reverse_iterator        rbegin()        {return reverse_iterator(this->end());}
    const_reverse_iterator  rbegin() const  {return const_reverse_iterator(this->end());}
    reverse_iterator        rend()          {return reverse_iterator(this->begin());}
    const_reverse_iterator  rend() const    {return const_reverse_iterator(this->begin());}

// CAPACITY
    size_type   size() const                    {return (this->_size);}
    size_type   max_size() const                {return (_alloc.max_size());}
    size_type   capacity() const                {return (this->_capacity);}
    void        resize(size_type sz, T c = T());
    bool        empty() const                   {return (_size == 0);}
    void        reserve(size_type n)
    {
        if (n > this->max_size())
            throw std::length_error("vector::reserve");
        if (n > _capacity)
        {
            value_type *temp;
            temp = _alloc.allocate(n);
            std::copy(this->begin(), this->end(), temp);
            _alloc.deallocate(&(*_array), _capacity);
            _array = temp;
            _capacity = n;
        }
    }

// ELEMENT ACCESS
    reference           operator[](size_type n)         {return(_array[n]);}
    const_reference     operator[](size_type n) const   {return(_array[n]);}
    const_reference     at(size_type n) const           {return(_array[n]);}
    reference           at(size_type n)                 {return(_array[n]);}
    reference           front()                         {return(_array[0]);}
    const_reference     front() const                   {return(_array[0]);}
    reference           back()                          {return(_array[_size - 1]);}
    const_reference     back() const                    {return(_array[_size - 1]);}

// MODIFIERS
    void            push_back(const T& x);
    void            pop_back();
    iterator        insert(iterator position, const T& x);
    void            insert(iterator position, size_type n, const T& x);
    template <class InputIterator>
    void            insert(iterator position, InputIterator first, InputIterator last);

    iterator        erase(iterator position);
    iterator        erase(iterator first, iterator last);
    void            swap(vector<T,Allocator>&x)
                    {std::swap(x._array, this->_array);
                    std::swap(x._size, this->_size);
                    std::swap(x._capacity, this->_capacity);}
    void            clear(void)
    {if(_size > 0){for (iterator it = this->begin(); it < this->end(); it++)
    {_alloc.destroy(&(*it));_size = 0;}}}

// OPERATORS
    friend bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
    {y.swap(x);}
    
private:
    allocator_type  _alloc;
    size_type       _size;
    size_type       _capacity;
    value_type*     _array;
    void            _shift_from_to(iterator from, iterator to)
    {
        for(size_type i = 0; i != (_size - 1 - from); i++) //n'importe quoiiiiiii
            std::copy(_array(_size - ), this->end - 1)
    }
};
}

#endif
