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
    // std ci-dessous a modifier lorsque les iterateurs seront ope :
    // typedef typename std::iterator                      iterator;
    // typedef typename std::const_iterator                const_iterator;
    typedef typename Allocator::reference               reference;
    typedef typename Allocator::const_reference         const_reference;
    typedef typename Allocator::pointer                 pointer;
    typedef typename Allocator::const_pointer           const_pointer;
    // typedef std::reverse_iterator<iterator>             reverse_iterator;
    // typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;

private:
    allocator_type  _base;
    size_type       _size;
    pointer         _begin;
    pointer         _end;

// Called by constructors to check initial size.
    static size_type
    _check_init_len(size_type n, const allocator_type& a)
    {
        if (n > std::allocator_traits::_S_max_size(std::allocator_traits::_Tp_alloc_type(a)))
            // __throw_length_error(__N("cannot create std::vector larger than max_size()"));
        return n;
    }

public:
// CONSTRUCTORS / DESTRUCTORS
    vector(void):_base(){}
    explicit vector(const Allocator& = Allocator() a): _base(a) {} // lign 497
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
    // vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
    // template <class InputIterator>
    // void assign(InputIterator first, InputIterator last){erase(begin(), end()); insert(begin(), first, last);}
    // void assign(size_type n, const T& u){erase(begin(), end()); insert(begin(), n, t);}
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
//     size_type   size() const;
//     size_type   max_size() const;
//     void        resize(size_type sz, T c = T());
//     size_type   capacity() const;
//     bool        empty() const;
//     void        reserve(size_type n);

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
    iterator        insert(iterator position, const T& x)
    {
        
    }

    void            insert(iterator position, size_type n, const T& x)
    {
        _M_fill_insert(__position, __n, __x);
    }

    template <class InputIterator>
    void            insert(iterator position, InputIterator first, InputIterator last)
    {

    }

    // iterator        erase(iterator position);
    // iterator        erase(iterator first, iterator last);
    // void            swap(vector<T,Allocator>&){x.swap(y);}
    void            clear(void)
    {
        if (size_type __n = _end - _begin)
          {
            std::_Destroy(_begin, _end, Allocator());
            _end = _begin;
          }
    };

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
}

#endif
