/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:39:07 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/09 18:25:48 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void basicTest(MutantStack<int>& mstack)
{
    std::cout << GREEN "Basic Test" RESET << std::endl; 

    mstack.push(5); // Adds element to top of stack
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
    ++it; // Skip first element
    --it; // Reset to first element
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}
void testList(std::list<int> list)
{
    std::cout << GREEN "List Test" RESET << std::endl;
    list.push_back(5);
    list.push_back(17);
    
    std::cout << "Back: " << list.back() << std::endl;
    
    list.pop_back();
    std::cout << "Size: " << list.size() << std::endl;
    
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::cout << "Iterating through list:" << std::endl;
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

int main()
{

    MutantStack<int> mstack;
    basicTest(mstack);

    std::list<int> list;
    testList(list);
    
    return 0;
}