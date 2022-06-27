/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:45:29 by cproesch          #+#    #+#             */
/*   Updated: 2022/06/27 17:58:43 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

//  !!!!!!! COMMENT STD::STACK PEUT FONCTIONNER ALORS QUE JE N'INCLUDE PAS
//  <STACK> NI <VECTOR> ???????

void test_stack(void)
{
    STACK<int> mystack;

    std::cout << "Is my stack empty ? (1 = Yes, 0 = No) = " << mystack.empty() << std::endl;
    std::cout << "Adding -1, 666666666 and 1" << std::endl;
    mystack.push(-1);
    mystack.push(666666666);
    mystack.push(1);
    std::cout << "Is my stack empty ? (1 = Yes, 0 = No) = " << mystack.empty() << std::endl;
    std::cout << "My stack's top = " << mystack.top() << std::endl;
    std::cout << "My stack size  = " << mystack.size() << std::endl;
    std::cout << "Popping from my stack " << std::endl;
    mystack.pop();
    std::cout << "My stack's top = " << mystack.top() << std::endl;
    std::cout << "My stack size  = " << mystack.size() << std::endl;
    std::cout << "Adding 0" << std::endl;
    mystack.push(0);
    std::cout << "My stack's top = " << mystack.top() << std::endl;
    std::cout << "My stack size  = " << mystack.size() << std::endl;

    STACK<int> mysecondstack;
    STACK<int> mythirdstack;
    mysecondstack = mystack;
    std::cout << "inferieur : " << (mystack < mysecondstack) << std::endl;
    std::cout << "superieur : " << (mystack > mysecondstack) << std::endl;
    std::cout << "egal      : " << (mystack == mysecondstack) << std::endl;
    std::cout << "different : " << (mystack != mysecondstack) << std::endl;
    std::cout << "inferieur : " << (mythirdstack < mystack) << std::endl;
    std::cout << "superieur : " << (mythirdstack > mystack) << std::endl;
    std::cout << "egal      : " << (mythirdstack == mystack) << std::endl;
    std::cout << "different : " << (mythirdstack != mystack) << std::endl;

    return;
}
