#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

// Function to print a container
template <typename Container>
void printContainer(const Container& container) {
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Merge-insert sort algorithm for std::vector
void mergeInsertSortVector(std::vector<int>& vec) {
    // Implement the Ford-Johnson algorithm for std::vector
    std::sort(vec.begin(), vec.end()); // Placeholder for actual algorithm
}

// Merge-insert sort algorithm for std::deque
void mergeInsertSortDeque(std::deque<int>& deq) {
    // Implement the Ford-Johnson algorithm for std::deque
    std::sort(deq.begin(), deq.end()); // Placeholder for actual algorithm
}

// Explicit instantiation of the template function
template void printContainer(const std::vector<int>& container);
template void printContainer(const std::deque<int>& container);