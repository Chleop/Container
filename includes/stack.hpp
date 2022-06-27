/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:16:57 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/27 17:02:32 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

namespace ft
{
    template <class T, class Container = std::vector<T> >
    class stack {
    public:
        typedef typename    Container::value_type       value_type;
        typedef typename    Container::size_type        size_type;
        typedef typename    Container::reference        reference;
        typedef typename    Container::const_reference  const_reference;
        typedef             Container                   container_type;
    
    protected:
        Container c;
    
    public:
        explicit stack(const Container& = Container()){return;}
        bool empty() const              { return c.empty(); }
        size_type size() const          { return c.size(); }
        value_type& top()               { return c.back(); }
        const value_type& top() const   { return c.back(); }
        void push(const value_type& x)  { c.push_back(x); }
        void pop()                      { c.pop_back(); }
        bool operator=(const stack<T, Container>& rhs)
        {
            if (this->c != rhs)
                this->c = rhs;
            return *this;
        }
    };


    template <class T, class Container>
    bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)
    {return x==y;}

    template <class T, class Container>
    bool operator< (const stack<T, Container>& x, const stack<T, Container>& y)
    {return x<y;}

    template <class T, class Container>
    bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
    {return x!=y;}

    template <class T, class Container>
    bool operator> (const stack<T, Container>& x, const stack<T, Container>& y)
    {return x>y;}

    template <class T, class Container>
    bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
    {return x>=y;}

    template <class T, class Container>
    bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
    {return x<=y;}

}

#endif