#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <set>
#include <deque>


/* FORD-JOHSON ALGORITM 
1. Divide the list into pairs of elements.
2. Sort each pair.
3. Merge the sorted pairs into a single list.
4. Insert any remaining elements into the merged list.*/

/*
Initial Vector [3, 6, 8, 2]
Step-by-Step Execution
1. Initial Call to mergeInsertSort
- mergeInsertSort(vec) is called with vec = [3, 6, 8, 2].
2. First Call to fordJohnsonSort
- fordJohnsonSort(vec, 0, 3) is called.
- mid = 0 + (3 - 0) / 2 = 1.
3. Recursive Calls to fordJohnsonSort
- fordJohnsonSort(vec, 0, 1) is called.
    mid = 0 + (1 - 0) / 2 = 0.
    fordJohnsonSort(vec, 0, 0) is called and returns immediately (base case).
    fordJohnsonSort(vec, 1, 1) is called and returns immediately (base case).
    merge(vec, 0, 0, 1) is called to merge [3] and [6].
        -Result after merge: [3, 6, 8, 2].
- fordJohnsonSort(vec, 2, 3) is called.
    mid = 2 + (3 - 2) / 2 = 2.
    fordJohnsonSort(vec, 2, 2) is called and returns immediately (base case).
    fordJohnsonSort(vec, 3, 3) is called and returns immediately (base case).
    merge(vec, 2, 2, 3) is called to merge [8] and [2].
        - Result after merge: [3, 6, 2, 8].
4. Final Merge
merge(vec, 0, 1, 3) is called to merge [3, 6] and [2, 8].
    - Result after merge: [2, 3, 6, 8].
*/

// Parse input arguments into a vector of integers
std::vector<int> parseInput(int argc, char **argv) {
    if (argc < 2) {
        throw std::runtime_error("Error: No input sequence provided");
    }
    std::vector<int> sequence;
    std::set<int> uniqueValues;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (!std::all_of(arg.begin(), arg.end(), ::isdigit)) {
            throw std::runtime_error("Error: Invalid input, non-numeric value");
        }
        int num = std::stoi(arg);
        if (num <= 0) {
            throw std::runtime_error("Error: Only positive integers allowed");
        }
        if (!uniqueValues.insert(num).second) {
            throw std::runtime_error("Error: Duplicate values not allowed");
        }
        sequence.push_back(num);
    }
    return sequence;
}

void processSequence(int argc, char **argv) {
    try {
        // Parse input sequence
        std::vector<int> vec = parseInput(argc, argv);
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
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
