/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   understanding_vectors.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:20:57 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/11 11:27:14 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
// #include "../includes/Vector.hpp"

// TO UNDERSTAND CONSTRUCTORS
// int    main(void)
// {
//     std::vector<int> first;                                // empty vector of ints
//     std::vector<int> second (4,100);                       // four ints with value 100
//     std::vector<int> third (second.begin(),second.end());  // iterating through second
//     std::vector<int> fourth (third);                       // a copy of third
//     int myints[] = {16,2,77,29};
//     std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    // the iterator constructor can also be used to construct from arrays

//     std::cout << "The content of first is:";
//     for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
//          std::cout << ' ' << *it;
//     std::cout << '\n';
    // std::cout << "The content of second is:";
    // for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    //      std::cout << ' ' << *it;
    // std::cout << '\n';
//     std::cout << "The content of third is:";
//     for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
//          std::cout << ' ' << *it;
//     std::cout << '\n';
//     std::cout << " third size is : " << third.size() << std::endl;
//     std::cout << " third capacity is : " << third.capacity() << std::endl;
//     third.push_back(16);
//     std::cout << " AFTER pushback third size is : " << third.size() << std::endl;
//     std::cout << " third capacity is : " << third.capacity() << std::endl;
    // std::cout << "The content of fourth is:";
    // for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
    //      std::cout << ' ' << *it;
    // std::cout << '\n';
    // std::cout << "The content of fifth is:";
    // for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    //      std::cout << ' ' << *it;
    // std::cout << '\n';

//     std::vector<int> sixth;
//     sixth = third;
//     std::cout << "The content of sixth is:";
//     for (std::vector<int>::iterator it = sixth.begin(); it != sixth.end(); ++it)
//          std::cout << ' ' << *it;
//     std::cout << '\n';
//     std::cout << " sixth size is : " << sixth.size() << std::endl;
//     std::cout << " sixth capacity is : " << sixth.capacity() << std::endl;
//     return 0;
// }

// TO UNDERSTAND SIZE AND CAPACITY
// int    main(void)
// {

//     std::vector<int> v0 (23, 100);
//     std::cout << "v0 MAX size: " << v0.max_size() << std::endl;
//     std::vector<int> v1 (5, 100);
//     std::cout << "v1 MAX size: " << v1.max_size() << std::endl;


    // std::vector<int> v1 (2, 100);

    // std::cout << "\033[32m### The content of v1 is:\033[37m" << std::endl;
    // for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << std::endl;
    // std::cout << "v1 size: " << v1.size() << std::endl;
    // std::cout << "v1 capacity: " << v1.capacity() << std::endl;

    // std::cout << "\033[32m### Adding one element\033[37m" << std::endl;
    // v1.push_back(16);
    // std::cout << "The content of v1 is:";
    // for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << std::endl;
    // std::cout << "v1 size: " << v1.size() << std::endl;
    // std::cout << "v1 capacity: " << v1.capacity() << std::endl;

    // std::cout << "\033[32m### Adding one element\033[37m" << std::endl;
    // v1.push_back(16);
    // std::cout << "The content of v1 is:";
    // for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << std::endl;
    // std::cout << "v1 size: " << v1.size() << std::endl;
    // std::cout << "v1 capacity: " << v1.capacity() << std::endl;

    // std::cout << "\033[32m### Adding one element\033[37m" << std::endl;
    // v1.push_back(16);
    // std::cout << "The content of v1 is:";
    // for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << std::endl;
    // std::cout << "v1 size: " << v1.size() << std::endl;
    // std::cout << "v1 capacity: " << v1.capacity() << std::endl;

    // std::cout << "\033[32m### Adding 4 elements\033[37m" << std::endl;
    // v1.push_back(10);
    // v1.push_back(10);
    // v1.push_back(10);
    // v1.push_back(10);
    // std::cout << "The content of v1 is:";
    // for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << std::endl;
    // std::cout << "v1 size: " << v1.size() << std::endl;
    // std::cout << "v1 capacity: " << v1.capacity() << std::endl;

    // std::cout << "\033[32m### Removing 4 elements\033[37m" << std::endl;
    // v1.pop_back();
    // v1.pop_back();
    // v1.pop_back();
    // v1.pop_back();
    // std::cout << "The content of v1 is:";
    // for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << std::endl;
    // std::cout << "v1 size: " << v1.size() << std::endl;
    // std::cout << "v1 capacity: " << v1.capacity() << std::endl;

    // std::cout << "\033[32m### Removing 5 elements\033[37m" << std::endl;
    // v1.pop_back();
    // v1.pop_back();
    // v1.pop_back();
    // v1.pop_back();
    // v1.pop_back();
    // std::cout << "The content of v1 is:";
    // for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << std::endl;
    // std::cout << "v1 size: " << v1.size() << std::endl;
    // std::cout << "v1 capacity: " << v1.capacity() << std::endl;
// 
//     return 0;
// }

// TO UNDERSTAND RBEGIN
// int main(void)
// {
//     std::vector<int> v1(1, 9);
//     v1.push_back(10);
//     v1.push_back(11);
//     v1.push_back(12);
//     v1.push_back(13);
//     std::cout << *(std::vector<int>::reverse_iterator(v1.rbegin())) << std::endl;
//     std::cout << *(std::vector<int>::reverse_iterator(v1.end())) << std::endl;

//     return 0;
// }

// TO UNDERSTAND SWAP
// int main(void)
// {
//     std::vector<int> foo (3,100);   // three ints with a value of 100
//     std::cout << "foo size: " << foo.size() << std::endl;
//     std::cout << "foo capacity: " << foo.capacity() << std::endl;
//     std::vector<int> bar (5,200);   // five ints with a value of 200
//     std::cout << "bar size: " << bar.size() << std::endl;
//     std::cout << "bar capacity: " << bar.capacity() << std::endl;

//     foo.swap(bar);

//     std::cout << "foo contains:";
//     for (unsigned i=0; i<foo.size(); i++)
//         std::cout << ' ' << foo[i];
//     std::cout << std::endl;
//     std::cout << "foo size: " << foo.size() << std::endl;
//     std::cout << "foo capacity: " << foo.capacity() << std::endl;

//     std::cout << "bar contains:";
//     for (unsigned i=0; i<bar.size(); i++)
//         std::cout << ' ' << bar[i];
//     std::cout << std::endl;
//     std::cout << "bar size: " << bar.size() << std::endl;
//     std::cout << "bar capacity: " << bar.capacity() << std::endl;

//   return 0;
// }

// TO UNDERSTAND COPY BACKWARD
// int main (void)
// {
//     std::vector<int> v1(2,3);
//         std::cout   << std::endl
//                 << "The content is : ";
// // Iterators, begin, end
//     for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
//         std::cout << ' ' << *it;
//     std::cout << std::endl;
//     v1.reserve(20);
//     std::vector<int>v2(5,6);
//     std::copy_backward(v2.begin(), v2.end(), v1.begin() + 8);
// // Size
//     std::cout << " size is : " << v1.size() << std::endl;
// // Capacity
//     std::cout << " capacity is : " << v1.capacity() << std::endl;
//     std::cout   << std::endl
//                 << "The content is : ";
// // Iterators, begin, end
//     for (std::vector<int>::iterator it = v1.begin(); it != v1.end() + 6; ++it)
//         std::cout << ' ' << *it;
//     std::cout << std::endl;
//     std::cout << std::endl;
//     return 0;
// }

// TO UNDERSTAND INSERT
// int main (void)
// {
//     std::vector<int> v1(2,3);
//     for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
//         std::cout << ' ' << *it;
//     std::cout << std::endl;
//     std::cout << " size is : " << v1.size() << std::endl;
//     std::cout << " capacity is : " << v1.capacity() << std::endl;

//     v1.insert(v1.begin() + 1, 5, 5);
    
//     for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
//         std::cout << ' ' << *it;
//     std::cout << std::endl;
//     std::cout << " size is : " << v1.size() << std::endl;
//     std::cout << " capacity is : " << v1.capacity() << std::endl;

//     v1.insert(v1.begin() + 1, 5, 5);
    
//     for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
//         std::cout << ' ' << *it;
//     std::cout << std::endl;
//     std::cout << " size is : " << v1.size() << std::endl;
//     std::cout << " capacity is : " << v1.capacity() << std::endl;

//     v1.insert(v1.begin() + 1, 13, 5);
    
//     for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
//         std::cout << ' ' << *it;
//     std::cout << std::endl;
//     std::cout << " size is : " << v1.size() << std::endl;
//     std::cout << " capacity is : " << v1.capacity() << std::endl;

//         v1.insert(v1.begin() + 1, 5, 5);
    
//     for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
//         std::cout << ' ' << *it;
//     std::cout << std::endl;
//     std::cout << " size is : " << v1.size() << std::endl;
//     std::cout << " capacity is : " << v1.capacity() << std::endl;

//             v1.insert(v1.begin() + 1, 21, 5);
    
//     for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
//         std::cout << ' ' << *it;
//     std::cout << std::endl;
//     std::cout << " size is : " << v1.size() << std::endl;
//     std::cout << " capacity is : " << v1.capacity() << std::endl;
//     return 0;
// }

// TO UNDERSTAND ASSIGN
int main (void)
{
    std::vector<int> v1(2, 3);
    int tab [] = {14, 25, 37, 48, 54, 6};
    std::vector<int> v2(tab, tab + 6);

    for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
    std::cout << " size is : " << v1.size() << std::endl;
    std::cout << " capacity is : " << v1.capacity() << std::endl;

    v1.assign(v2.begin(), v2.end()+2);
    
    for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
    std::cout << " size is : " << v1.size() << std::endl;
    std::cout << " capacity is : " << v1.capacity() << std::endl;

    return 0;
}