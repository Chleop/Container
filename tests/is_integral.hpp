/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:24:20 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/20 18:42:25 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL
# define IS_INTEGRAL

namespace ft
{
    
    template <class T, T v>
    struct integral_constant {
        typedef T value_type;
        constexpr operator value_type() const noexcept { return v; }
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;
    template <class T>
    struct is_integral : public false_type{};
    template <>
    struct is_integral<bool> : public true_type{};
    template <>
    struct is_integral<char> : public true_type{};
    template <>
    struct is_integral<signed char> : public true_type{};
    template <>
    struct is_integral<unsigned char> : public true_type{};
    template <>
    struct is_integral<wchar_t> : public true_type{};
    template <>
    struct is_integral<short> : public true_type{};
    template <>
    struct is_integral<int> : public true_type{};
    template <>
    struct is_integral<long> : public true_type{};
    template <>
    struct is_integral<long long> : public true_type{};
    template <>
    struct is_integral<unsigned short> : public true_type{};
    template <>
    struct is_integral<unsigned int> : public true_type{};
    template <>
    struct is_integral<unsigned long> : public true_type{};
    template <>
    struct is_integral<unsigned long long> : public true_type{};
    template <>
    struct is_integral<char16_t> : public true_type{};
    template <>
    struct is_integral<char32_t> : public true_type{};
}

#endif
