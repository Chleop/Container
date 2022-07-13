/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:04:31 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/13 19:24:33 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "is_integral.hpp"
# include "lex_compare.hpp"
# include "enable_if.hpp"

namespace ft 
{
template <class T, class Allocator = std::allocator<T> >
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
        {for(size_type i = 0; i < _size; i++)
            _alloc.construct(&(_array[i]), val);}
// Range
    template <class InputIterator>
    vector(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& a = allocator_type()):
        _alloc(a), 
        _size(last - first),  
        _capacity(_size), 
        _array(_alloc.allocate(_size))
        {for(size_type i = 0; i < _size; i++)
            _alloc.construct(&(_array[i]), *(first + i));}
        // {copy(first, last, begin());}
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
                            {
                                clear();
                                _alloc.deallocate(&(*_array), _capacity);
                            }
                            _array = _alloc.allocate(x._size);
                            _capacity = x._size;}
                        _size = x._size;
                        for(size_type i = 0; i < x.size(); i++)
                            _alloc.construct(&(_array[i]), x[i]);
                        // copy(x.begin(), x.end(), begin());
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
                {if (n > _capacity)
                {if (n > max_size())
                    throw std::length_error("vector::reserve");
                value_type *temp;
                size_type   new_size = _size;
                temp = _alloc.allocate(n);
                if (_size != 0)
                    {for(size_type i = 0; i < _size; i++)
                        _alloc.construct(&(temp[i]), _array[i]);
                    clear();
                    _alloc.deallocate(&(*_array), _capacity);}
                _array = temp;
                _size = new_size;
                _capacity = n;}}

// ELEMENT ACCESS
    reference           operator[](size_type n)         {return*(_array + n);}
    const_reference     operator[](size_type n) const   {return*(_array + n);}
    const_reference     at(size_type n) const           {if (n > _size - 1) throw std::out_of_range("vector::at");
                                                        return(_array[n]);}
    reference           at(size_type n)                 {if (n > _size - 1) throw std::out_of_range("vector::at");
                                                        return(_array[n]);}
    reference           front()                         {return(_array[0]);}
    const_reference     front() const                   {return(_array[0]);}
    reference           back()                          {return(_array[_size - 1]);}
    const_reference     back() const                    {return(_array[_size - 1]);}

    // void print_array(std::string u)
    // {
    //     std::cout << "PRINTING ARRAY : " << u << std::endl;
    //     for (size_t i = 0; i<_size; i++)
    //         std::cout << _array[i] << std::endl;
    // }

// MODIFIERS
    void            insert(iterator position, size_type n, const T& x)
                    {difference_type   diff = position - begin();
                    if (n == 0)
                        return;
                    if (_capacity < _size + n)
                        reallocate(_size + n);
                    for(size_type i = _size + n - 1; i != diff + n - 1; i--)
                    {if (i < _size)
                        _alloc.destroy(&(_array[i]));
                    _alloc.construct(&(_array[i]), _array[i - n]);}

                    // copy_backward(begin() + diff, begin() + _size,\
                    // begin() + _size + n);
                    for(size_type i = diff; i < diff + n; i++)
                    {if (i < _size)
                        _alloc.destroy(&(_array[i]));
                    _alloc.construct(&(_array[i]), x);}
                    // fill(begin() + diff, begin() + diff + n, x);

                    _size = _size + n;}
    iterator        insert(iterator position, const T& x)
                    {difference_type   diff = position - begin();
                    insert(begin() + diff, 1, x);
                    return (begin() + diff);}
    template <class InputIterator>
    void            insert(iterator position, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
                    {size_type    pos = position - begin();
                    size_type           added_size = last - first;
                    if (added_size == 0)
                        return;
                    if (_capacity < _size + added_size)
                        reallocate(_size + added_size);
                    
                    // copy_backward(begin() + pos, begin() + _size,\
                    // begin() + _size + added_size);
                    for(size_type i = _size + added_size - 1; i != pos + added_size - 1; i--)
                    {_alloc.destroy(&(_array[i]));
                    _alloc.construct(&(_array[i]), _array[i - added_size]);}
                    // copy(first, last, begin() + pos);
                    for(size_type i = pos; i < pos + added_size; i++)
                    {_alloc.destroy(&(_array[i]));
                    _alloc.construct(&(_array[i]), *(first++));}

                    _size = _size + added_size;}
    iterator        erase(iterator position)
                    {iterator it = position;
                    for (; it < (end() - 1); it++)
                    {
                        _alloc.destroy(&(*it));
                        _alloc.construct(&(*it), *(it + 1));
                    }
                    _alloc.destroy(&(*it));
                    _size--;
                    return position;}
    iterator        erase(iterator first, iterator last)
                    {size_type diff_size = last - first;
                    iterator it = first;
                    for (; it < (end() - diff_size); it++)
                    {
                        _alloc.destroy(&(*it));
                        _alloc.construct(&(*it), *(it + diff_size));
                    }
                    for (; it < end(); it++)
                        _alloc.destroy(&(*it));
                    _size = _size - diff_size;
                    return first;}
    void            clear(void)
                    {erase(begin(), end());}
    void            push_back(const T& x)
                    {if (_capacity != 0) {insert(end(), x);}
                    else {reallocate(1);insert(end(), x);}}
    void            pop_back()
                    {erase(end() - 1);}
    void            swap(vector<T,Allocator>&x)
                    {std::swap(x._array, this->_array);
                    std::swap(x._size, this->_size);
                    std::swap(x._capacity, this->_capacity);}

// OPERATORS
    friend bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {if (x._size != y._size)return false;
    return (std::equal (x.begin(), x.end(), y.begin()));}
    friend bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {return !(x == y);}
    friend bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));}
    friend bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {return (!(x < y) && !(x == y));}
    friend bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {return !(x < y);}
    friend bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {return (x < y) || (x == y);}
    friend void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
    {y.swap(x);}
    
private:
    allocator_type  _alloc;
    size_type       _size;
    size_type       _capacity;
    value_type*     _array;
    void            reallocate(size_type n)
                    {if ((n - _size) > _size)
                        reserve(n);
                    else
                        reserve(_size + _size);}
    // template <class InputIterator>
    // void            copy_backward(InputIterator first, InputIterator last, iterator result)
    //                 {
    //                     size_type diff_size = last - first;
    //                     size_type end_result = result - begin();
    //                     for(size_type i = end_result - 1; i != end_result - diff_size - 1; i--)
    //                     {
    //                         if (i < _size)
    //                             _alloc.destroy(&(_array[i]));
    //                         _alloc.construct(&(_array[i]), *(last--));
    //                     }
    //                 }
    // template <class InputIterator>
    // void            copy(InputIterator first, InputIterator last, iterator result)
    //                 {
    //                     size_type diff_size = last - first;
    //                     size_type start_result = result - begin();
    //                     for(size_type i = start_result; i != start_result + diff_size; i++)
    //                     {
    //                         if (i < _size)
    //                             _alloc.destroy(&(_array[i]));
    //                         _alloc.construct(&(_array[i]), *(first++));
    //                     }
    //                 }


};
}

#endif
