#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    try {
        for (int i = 1; i < argc; ++i) {
            int num = std::stoi(argv[i]);
            if (num <= 0) throw std::invalid_argument("Non-positive integer");
            vec.push_back(num);
            deq.push_back(num);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: Invalid input." << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    printContainer(vec);

    auto start = std::chrono::high_resolution_clock::now();
    mergeInsertSortVector(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durationVector = end - start;

    start = std::chrono::high_resolution_clock::now();
    mergeInsertSortDeque(deq);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durationDeque = end - start;

    std::cout << "After: ";
    printContainer(vec);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << durationVector.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << durationDeque.count() << " us" << std::endl;

    return 0;
}