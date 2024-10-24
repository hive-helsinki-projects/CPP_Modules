/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:13:21 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/24 12:22:09 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

void testVector() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Test value present
    try {
        int found = easyfind(vec, 3);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test value absent
    try {
        int found = easyfind(vec, 6);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

void testList() {
    std::list<int> lst = {10, 20, 30, 40, 50};

    // Test value present
    try {
        int found = easyfind(lst, 30);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test value absent
    try {
        int found = easyfind(lst, 60);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

void testDeque() {
    std::deque<int> deq = {1, 2, 3, 4, 5};

    // Test value present
    try {
        int found = easyfind(deq, 3);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test value absent
    try {
        int found = easyfind(deq, 6);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

void testLargeContainer() {
    std::vector<int> largeVec(1000000, 1); // 1 million elements, all 1
    largeVec[999999] = 2; // Set the last element to 2

    // Test value present
    try {
        int found = easyfind(largeVec, 2);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test value absent
    try {
        int found = easyfind(largeVec, 3);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

int main() {

    std::cout << "Testing with std::vector:" << std::endl;
    testVector();

    std::cout << "\nTesting with std::list:" << std::endl;
    testList();

    std::cout << "\nTesting with std::deque:" << std::endl;
    testDeque();

    std::cout << "\nTesting with large container:" << std::endl;
    testLargeContainer();

    return 0;
}