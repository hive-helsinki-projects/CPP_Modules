/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:39:07 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/09 17:33:37 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
    std::cout << GREEN "Basic Test" RESET << std::endl; 
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop(); // Removes the top element
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating through stack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    // Test copy constructor
    std::cout << GREEN "\nTest copy constructor" RESET << std::endl;
    MutantStack<int> copyStack(mstack);
    std::cout << "Copy stack contents:" << std::endl;
    for (auto it = copyStack.begin(); it != copyStack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // Test assignment operator
    std::cout << GREEN "\nTest assignment operator" RESET << std::endl;
    MutantStack<int> assignStack;
    assignStack = mstack;
    std::cout << "Assigned stack contents:" << std::endl;
    for (auto it = assignStack.begin(); it != assignStack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // Test with different data types
    std::cout << GREEN "\nTest with different data types" RESET << std::endl;
    MutantStack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << "String stack contents:" << std::endl;
    for (auto it = stringStack.begin(); it != stringStack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // Test with standard stack
    std::cout << GREEN "\nTest with standard stack" RESET << std::endl;
    std::stack<int> s1(mstack);
    std::cout << "Standard stack contents:" << std::endl;
    while (!s1.empty())
    {
        std::cout << s1.top() << std::endl;
        s1.pop();
    }

    return 0;
}