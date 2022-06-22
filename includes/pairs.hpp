/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairs.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:22:30 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/22 15:41:50 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIRS_HPP
# define PAIRS_HPP

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        
    public:
// Member types
        typedef T1 first_type;
        typedef T2 second_type;
        
// Member objects
        T1 first;
        T2 second;

// Constructors
        pair(): first(T1()), second(T2()){}
        pair(const T1& x, const T2& y): first(x), second(y){}
        template<class U, class V>
        pair(const pair<U, V> &p): first(p.first), second(p.second){}

// Destructor
        ~pair(void){}

// Operators
        pair& operator=(const pair<T1,T2>& other)
        {if (this != &other){first = other.first;second = other.second;}return *this;}
    };

// Non-member functions
    template <class T1, class T2>
    bool operator==(const pair<T1,T2>& x, const pair<T1,T2>& y)
    {std::cout << "JE SUIS LA FT" << std::endl;return(x.first == y.first && x.second == y.second);}
    template <class T1, class T2>
    bool operator!=(const pair<T1,T2>& x, const pair<T1,T2>& y)
    {return(x.first != y.first || x.second != y.second);}
    template <class T1, class T2>
    bool operator< (const pair<T1,T2>& x, const pair<T1,T2>& y)
    {return(x.first < y.first || (!(y.first < x.first) && x.second < y.second));}
    template <class T1, class T2>
    bool operator<=(const pair<T1,T2>& x, const pair<T1,T2>& y)
    {return(x.first <= y.first || (!(y.first <= x.first) && x.second <= y.second));}
    template <class T1, class T2>
    bool operator> (const pair<T1,T2>& x, const pair<T1,T2>& y)
    {return(x.first > y.first || (!(y.first > x.first) && x.second > y.second));}
    template <class T1, class T2>
    bool operator>=(const pair<T1,T2>& x, const pair<T1,T2>& y)
    {return(x.first >= y.first || (!(y.first >= x.first) && x.second >= y.second));}
    template <class T1, class T2>
    pair<T1,T2> make_pair(const T1& x, const T2& y)
    {return pair<T1, T2>(x, y);}
    
}

#endif
