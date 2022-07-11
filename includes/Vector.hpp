/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:04:31 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/11 14:58:19 by cproesch         ###   ########.fr       */
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
        _capacity(0),
        _array(NULL)
        {}
// Fill
    explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& a = allocator_type()):
        _alloc(a), 
        _size(n),  
        _capacity(n), 
        _array(_alloc.allocate(n))
        {std::fill(begin(), end(), val);}
// Range
    template <class InputIterator, class = typename ft::enable_if<ft::is_integral<InputIterator>::value == false>::type>
    vector(InputIterator first, InputIterator last, const allocator_type& a = allocator_type()):
        _alloc(a), 
        _size(last - first),  
        _capacity(_size), 
        _array(_alloc.allocate(_size))
        {std::copy(first, last, begin());}
// Copy
    vector(const vector<T,Allocator>& x):
        _alloc(x._alloc), 
        _size(0), 
        _capacity(0),
        _array(NULL)
        {*this = x;}
// Destructor
    ~vector()
        {clear();if (_capacity > 0)_alloc.deallocate(&(*_array), _capacity);}

// OPERATEUR ET FONCTIONS D'ASSIGNATION
    vector<T,Allocator>& operator=(const vector<T,Allocator>& x)
                        {if (_capacity < x._size)
                            {if (_capacity > 0)
                                _alloc.deallocate(&(*_array), _capacity);
                            _array = _alloc.allocate(x._size);
                            _capacity = x._size;}
                        _size = x._size;
                        std::copy(x.begin(), x.end(), begin());
                        return *this;}
    template <class InputIterator>
    void            assign(InputIterator first, InputIterator last)
                    {erase(begin(), end()); insert(begin(), first, last);}
    void            assign(size_type n, const T& u)
                    {erase(begin(), end()); insert(begin(), n, u);}
    allocator_type  get_allocator() const
                    {return _alloc;}

// ITERATORS
    iterator                begin()         {return iterator(_array);}
    const_iterator          begin() const   {return const_iterator(_array);}
    iterator                end()           {return iterator(_array + _size);}
    const_iterator          end() const     {return const_iterator(_array + _size);}
    reverse_iterator        rbegin()        {return reverse_iterator(end());}
    const_reverse_iterator  rbegin() const  {return const_reverse_iterator(end());}
    reverse_iterator        rend()          {return reverse_iterator(begin());}
    const_reverse_iterator  rend() const    {return const_reverse_iterator(begin());}

// CAPACITY
    size_type   size() const                    {return (this->_size);}
    size_type   max_size() const                {return (_alloc.max_size());}
    size_type   capacity() const                {return (this->_capacity);}
    bool        empty() const                   {return (_size == 0);}
    void        resize(size_type sz, T c = T())
                {if (sz < _size)erase(begin() + sz, end());
                else if (sz > _size)insert(end(), sz - _size, c);}
    void        reserve(size_type n)
                {if (n > max_size())
                    throw std::length_error("vector::reserve");
                if (n > _capacity)
                {value_type *temp;
                temp = _alloc.allocate(n);
                std::copy(begin(), end(), temp);
                _alloc.deallocate(&(*_array), _capacity);
                _array = temp;
                _capacity = n;}}

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
    void            insert(iterator position, size_type n, const T& x)
                    {difference_type   diff = position - begin();
                    if (_capacity < _size + n)
                        reallocate(_size + n);
                    std::copy_backward(begin() + diff, begin() + _size,\
                    begin() + _size + n);
                    std::fill(begin() + diff, begin() + diff + n, x);
                    _size = _size + n;}
    iterator        insert(iterator position, const T& x)
                    {difference_type   diff = position - begin();
                    insert(begin() + diff, 1, x);
                    return (begin() + diff);}
    template <class InputIterator, class = typename ft::enable_if<ft::is_integral<InputIterator>::value == false>::type>
    void            insert(iterator position, InputIterator first, InputIterator last)
                    {difference_type   diff = position - begin();
                    if (_capacity < _size + (last - first))
                        reallocate(_size + (last - first));
                    std::copy_backward(begin() + diff, begin() + _size,\
                    begin() + _size + (last - first));
                    std::copy(first, last, begin() + diff);
                    _size = _size + (last - first);}
    iterator        erase(iterator position)
                    {_alloc.destroy(&(*position));
                    insert(position, position + 1, end());
                    _size--;
                    return position;}   
    iterator        erase(iterator first, iterator last)
                    {for (iterator it = first; it < last; it++)
                        _alloc.destroy(&(*it));
                    insert(first, last, end());
                    _size = _size - (last - first);
                    return first;}
    void            clear(void)
                    {erase(begin(), end());}
    void            push_back(const T& x)
                    {insert(end(), x);}
    void            pop_back()
                    {erase(end() - 1);}
    void            swap(vector<T,Allocator>&x)
                    {std::swap(x, *this);}

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
    void            reallocate(size_type n)
                    {size_type   new_cap = _capacity;
                        if (n > _capacity)
                        {if (n > max_size())
                            throw std::length_error("vector::reallocate");
                        if ((n - _size) > _size)
                            new_cap = n;
                        else
                            new_cap = _size + _size;
                        value_type *temp;
                        temp = _alloc.allocate(new_cap);
                        std::copy(begin(), end(), temp);
                        _alloc.deallocate(&(*_array), _capacity);
                        _array = temp;
                        _capacity = new_cap;}}
};
}

#endif
