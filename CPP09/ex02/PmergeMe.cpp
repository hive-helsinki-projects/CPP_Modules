#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

/* FORD-JOHSON ALGORITM 
1. Divide the list into pairs of elements.
2. Sort each pair.
3. Merge the sorted pairs into a single list.
4. Insert any remaining elements into the merged list.*/

// Parse input arguments into a vector of integers
std::vector<int> PmergeMe::parseInput(int argc, char **argv) {
    if (argc < 2) {
        throw std::runtime_error("Error: No input sequence provided");
    }
    std::vector<int> sequence;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (!std::all_of(arg.begin(), arg.end(), ::isdigit)) {
            throw std::runtime_error("Error: Invalid input, non-numeric value");
        }
        int num = std::stoi(arg);
        if (num <= 0) {
            throw std::runtime_error("Error: Only positive integers allowed");
        }
        sequence.push_back(num);
    }
    return sequence;
}

// Merge-insert sort for std::vector
void PmergeMe::mergeInsertSortVector(std::vector<int>& sequence) {
    if (sequence.size() <= 1) return;

    // Implementing the Ford-Johnson algorithm
    for (size_t i = 1; i < sequence.size(); ++i) {
        int key = sequence[i];
        size_t j = i;
        while (j > 0 && sequence[j - 1] > key) {
            sequence[j] = sequence[j - 1];
            --j;
        }
        sequence[j] = key;
    }
}

// Merge-insert sort for std::deque
void PmergeMe::mergeInsertSortDeque(std::deque<int>& sequence) {
    if (sequence.size() <= 1) return;

    // Implementing the Ford-Johnson algorithm
    for (size_t i = 1; i < sequence.size(); ++i) {
        int key = sequence[i];
        size_t j = i;
        while (j > 0 && sequence[j - 1] > key) {
            sequence[j] = sequence[j - 1];
            --j;
        }
        sequence[j] = key;
    }
}

void PmergeMe::processSequence(int argc, char **argv) {
    try {
        // Parse input sequence
        std::vector<int> vec = parseInput(argc, argv);
        // Copy sequence to deque for second sorting
        std::deque<int> deq(vec.begin(), vec.end());

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
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
