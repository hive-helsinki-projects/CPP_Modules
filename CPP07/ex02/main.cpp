/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:59:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/23 14:09:58 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include <iostream>
#include <string>

int main() {
    // Test default constructor
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    // Test constructor with size parameter
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    Array<int> copyArray(intArray);
    std::cout << "Copy array size: " << copyArray.size() << std::endl;
    for (unsigned int i = 0; i < copyArray.size(); i++) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl;

    // Test assignment operator
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
    for (unsigned int i = 0; i < assignedArray.size(); i++) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;

    // Test subscript operator and exception handling
    try {
        intArray[2] = 42;
        std::cout << "intArray[2] = " << intArray[2] << std::endl;
        std::cout << "Accessing out of bounds element: " << intArray[10] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test with a different type
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";
    std::cout << "String array size: " << stringArray.size() << std::endl;
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}