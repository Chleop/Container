/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vectors.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:05:25 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/05 15:05:25 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename T>
void single_test(T vect, std::string str)
{
    std::cout   << std::endl
                << "The content of "
                << str
                << " is : ";
    for (typename T::iterator it = vect.begin(); it != vect.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
    std::cout << str << " max size is : " << vect.max_size() << std::endl;
    std::cout << str << " size is : " << vect.size() << std::endl;
    std::cout << str << " capacity is : " << vect.capacity() << std::endl;
    std::cout << std::endl;
    return;
}

void test_vectors(void)
{
    VECTOR<int> first;                                // empty vector of ints
    VECTOR<int> second (4, 100);                       // four ints with value 100
    // VECTOR<int> third (second.begin(),second.end());   // iterating through second
    // VECTOR<int> fourth (third);                        // a copy of third
    // int myints[] = {16, 2, 77, 29};                         // iterator constructor used to construct from arrays
    // VECTOR<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    single_test(first, "first");
    single_test(second, "second");
    // single_test(third, "third");
    return;
}