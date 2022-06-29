/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:06:53 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/29 17:47:10 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP 
# define ITERATORS_TRAITS_HPP

namespace ft
{
// This class does nothing but define nested typedefs.  The general
// version simply @a forwards the nested typedefs from the Iterator
// argument.  Specialized versions for pointers and pointers-to-const
// provide tighter, more correct semantics.
    template<typename _Iterator>
    struct iterator_traits
    {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type        value_type;
      typedef typename _Iterator::difference_type   difference_type;
      typedef typename _Iterator::pointer           pointer;
      typedef typename _Iterator::reference         reference;
    };

/// Partial specialization for pointer types.
    template<typename _Tp>
    struct iterator_traits<_Tp*>
    {
      typedef random_access_iterator_tag    iterator_category;
      typedef _Tp                           value_type;
      typedef ptrdiff_t                     difference_type;
      typedef _Tp*                          pointer;
      typedef _Tp&                          reference;
    };

/// Partial specialization for const pointer types.
    template<typename _Tp>
    struct iterator_traits<const _Tp*>
    {
      typedef random_access_iterator_tag    iterator_category;
      typedef _Tp                           value_type;
      typedef ptrdiff_t                     difference_type;
      typedef const _Tp*                    pointer;
      typedef const _Tp&                    reference;
    };

// If _Iterator has a base returns it otherwise _Iterator is returned
// untouched
    template<typename _Iterator, bool _HasBase>
    struct _Iter_base
    {
        typedef _Iterator iterator_type;
        static iterator_type _S_base(_Iterator __it)
        { return __it; }
    };
    template<typename _Iterator>
    struct _Iter_base<_Iterator, true>
    {
        typedef typename _Iterator::iterator_type iterator_type;
        static iterator_type _S_base(_Iterator __it)
        { return __it.base(); }
    };
}

#endif
