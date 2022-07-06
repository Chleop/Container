/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:04:31 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/06 18:27:20 by cproesch         ###   ########.fr       */
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
    typedef typename Allocator::reference                   reference;
    typedef typename Allocator::const_reference             const_reference;
    typedef typename Allocator::pointer                     pointer;
    typedef typename Allocator::const_pointer               const_pointer;
    typedef typename std::vector<T>::reverse_iterator       reverse_iterator;
    typedef typename std::vector<T>::const_reverse_iterator const_reverse_iterator;

// CONSTRUCTORS / DESTRUCTORS
// Default
    explicit vector(const allocator_type& a = allocator_type()):
    _alloc(a), _size(0), _capacity(0){}
// Fill
    explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& a = allocator_type()):
    _alloc(a), _size(n),  _capacity(n), _array(_alloc.allocate(n))
    {for (iterator it = this->begin(); it < this->end(); it++)*it = val;}
// Range
    template <class InputIterator, class = typename ft::enable_if<ft::is_integral<InputIterator>::value == false>::type>
    vector(InputIterator first, InputIterator last, const allocator_type& a = allocator_type()):
    _alloc(a), _size(last - first),  _capacity(_size), _array(_alloc.allocate(_size))
    {for (iterator it = this->begin(); it < this->end(); it++)
        {*it = *(first);first++;}}
// Copy
    vector(const vector<T,Allocator>& x):
    _alloc(x._alloc), _size(0), _capacity(0)
    {if(_capacity > 0) _array = _alloc.allocate(_capacity);*this = x;}
// Destructor
    ~vector()
    {clear();if (_capacity > 0)_alloc.deallocate(&(*_array), _capacity);}

// OPERATEUR ET FONCTIONS D'ASSIGNATION
    vector<T,Allocator>& operator=(const vector<T,Allocator>& x)
    {
        if (_capacity < x._size)
        {
            if (_capacity > 0)
                _alloc.deallocate(&(*_array), _capacity);
            _array = _alloc.allocate(x._size);
            _capacity = x._size;
        }
        _size = x._size;
        for (size_t i = 0; i < _size; i++)
            _array[i] = (x._array)[i];
        return *this;
    }
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last)
    {erase(begin(), end()); insert(begin(), first, last);}
    void assign(size_type n, const T& u)
    {erase(begin(), end()); insert(begin(), n, u);}
    allocator_type get_allocator() const
    {return _alloc;}

// ITERATORS
// ----------------------------->TO DO :voir s'il faut throw une erreur par exemple lorsqu'on fait un 
// begin() sur un vecteur non initialise (le std fait un segfault)
    iterator                begin()         {return iterator(_array);}
    const_iterator          begin() const   {return const_iterator(_array);}
    iterator                end()           {return iterator(_array + _size);}
    const_iterator          end() const     {return const_iterator(_array + _size);}
    reverse_iterator        rbegin()        {return reverse_iterator(this->begin());}
    const_reverse_iterator  rbegin() const  {return const_reverse_iterator(this->begin());}
    reverse_iterator        rend()          {return reverse_iterator(this->end());}
    const_reverse_iterator  rend() const    {return const_reverse_iterator(this->end());}

// CAPACITY
    size_type   size() const                    {return (this->_size);}
    size_type   max_size() const                {return (_alloc.max_size());}
    size_type   capacity() const                {return (this->_capacity);}
    void        resize(size_type sz, T c = T());
    bool        empty() const;
    void        reserve(size_type n);

// ELEMENT ACCESS
    reference           operator[](size_type index)
    {
        return(_array[index]);
    }
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
    void            insert(iterator position, size_type n, const T& x);
    template <class InputIterator>
    void            insert(iterator position, InputIterator first, InputIterator last);

    iterator        erase(iterator position);
    iterator        erase(iterator first, iterator last);
    void            swap(vector<T,Allocator>&x);  //{x.swap(y);}
    void            clear(void){if(_size > 0){for (iterator it = this->begin(); it < this->end(); it++)
                    {_alloc.destroy(&(*it));}}}

// OPERATORS
    friend bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    friend void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
    
private:
    allocator_type  _alloc;
    size_type       _size;
    size_type       _capacity;
    value_type*     _array;

};
}

#endif
