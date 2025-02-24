/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:22:56 by lkilpela          #+#    #+#             */
/*   Updated: 2025/02/24 19:49:23 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <set>
#include <deque>
#include <vector>

// Helper function to check if a string represents a valid integer
bool isValidInteger(const std::string& str) {
    if (str.empty()) return false;
    size_t start = (str[0] == '-') ? 1 : 0;
    return std::all_of(str.begin() + start, str.end(), ::isdigit);
}

// Parse input arguments into a vector of integers
std::vector<int> parseInput(int argc, char **argv) {
    std::vector<int> sequence;
    std::set<int> uniqueValues;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (!isValidInteger(arg)) {
            throw std::runtime_error("Error: Invalid input, non-numeric value " + arg);
        }
        int num = std::stoi(arg);
        if (num <= 0) {
            throw std::runtime_error("Error: Invalid input, non-positive value " + arg);
        }
        if (!uniqueValues.insert(num).second) {
            throw std::runtime_error("Error: Invalid input, duplicate value " + arg);
        }
        sequence.push_back(num);
    }
    return sequence;
}

// Function to process the input sequence
void processSequence(int argc, char **argv) {
    // Parse input sequence
    std::vector<int> vec = parseInput(argc, argv);
    if (isSorted(vec)) {
        throw std::runtime_error("Error: Sequence is already sorted");
    }
    // Copy sequence to deque for second sorting
    std::deque<int> deq(vec.begin(), vec.end());

    std::cout << "Before: ";
    printContainer(vec);

    double durationVector = measureSortTime(vec);
    double durationDeque = measureSortTime(deq);

    std::cout << "After: ";
    printContainer(vec);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << durationVector << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << durationDeque << " us" << std::endl;
}
