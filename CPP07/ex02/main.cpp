/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:59:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/23 14:19:27 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include <iostream>
#include <string>

int main() {
    // Test default constructor
    Array<int> emptyArray;
    std::cout << YELLOW "Empty array size: " RESET << emptyArray.size() << std::endl;

    // Test constructor with size parameter
    Array<int> intArray(5);
    std::cout << YELLOW "Int array size: " RESET << intArray.size() << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    Array<int> copyArray(intArray);
    std::cout << YELLOW "Copy array size: " RESET << copyArray.size() << std::endl;
    for (unsigned int i = 0; i < copyArray.size(); i++) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl;

    // Test assignment operator
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << YELLOW "Assigned array size: " RESET << assignedArray.size() << std::endl;
    for (unsigned int i = 0; i < assignedArray.size(); i++) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;

    // Test subscript operator and exception handling
    try {
        intArray[2] = 42;
        std::cout << YELLOW "intArray[2] = " << intArray[2] << std::endl;
        std::cout << YELLOW "Accessing out of bounds element: " RESET << intArray[10] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test with a different type
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";
    std::cout << YELLOW "String array size: " RESET << stringArray.size() << std::endl;
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}