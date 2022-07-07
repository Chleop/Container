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
void empty_test(T &vect, std::string str)
{
    std::cout   << std::endl
                << "The content of "
                << str
                << " is : ";
// Iterators, begin, end
    for (VECTOR<int>::iterator it = vect.begin(); it != vect.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
// Size
    std::cout << str << " size is : " << vect.size() << std::endl;
// Capacity
    std::cout << str << " capacity is : " << vect.capacity() << std::endl;
// Empty
    std::cout << str << " is empty ? : " << vect.empty() << std::endl;
    std::cout << std::endl;
}

template <typename T>
void single_test(T &vect, std::string str)
{
    std::cout   << std::endl
                << "The content of "
                << str
                << " is : ";
// Iterators, begin, end
    for (typename T::iterator it = vect.begin(); it != vect.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
// Max size
    std::cout << str << " max size is : " << vect.max_size() << std::endl;
// Size
    std::cout << str << " size is : " << vect.size() << std::endl;
// Capacity
    std::cout << str << " capacity is : " << vect.capacity() << std::endl;
// Rbegin
    std::cout << str << " rbegin is : " << *(vect.rbegin()) << std::endl;
// End
    std::cout << str << " end is : " << *(vect.end()) << std::endl;
// At
    std::cout << str << " at is : " << vect.at(2) << std::endl;
// Front
    std::cout << str << " front is : " << vect.front() << std::endl;
// Back
    std::cout << str << " back is : " << vect.back() << std::endl;
// Empty
    std::cout << str << " is empty ? : " << vect.empty() << std::endl;
    std::cout << std::endl;
    return;
}

void test_vectors(void)
{
    VECTOR<int> first;                                  // empty vector of ints
    VECTOR<int> second (4, 100);                        // four ints with value 100
    VECTOR<int> third (second.begin(),second.end());    // iterating through second
    VECTOR<int> fourth (third);                         // a copy of third
    int myints[] = {16, 2, 77, 29};                     // iterator constructor used to construct from arrays
    VECTOR<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    VECTOR<int> sixth (6, 666);
    sixth = fifth;                                      // assignment from smaller vector
    VECTOR<int> seven (2, 666);                         
    seven = fifth;                                      // assignment from bigger vector

    empty_test(first, "first");
    single_test(second, "second");
    single_test(third, "third");
    single_test(fourth, "fourth");
    single_test(fifth, "fifth");
    single_test(sixth, "sixth");
    single_test(seven, "seven");
// Swap
    fifth.swap(second);
    single_test(second, "second");
    single_test(fifth, "fifth");
// Clear
    fourth.clear();
    empty_test(fourth, "fourth");
// Reserve
    second.reserve(20);
    single_test(second, "second");
    return;
}