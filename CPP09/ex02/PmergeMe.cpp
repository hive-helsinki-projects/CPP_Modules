#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <set>

/* FORD-JOHSON ALGORITM 
1. Divide the list into pairs of elements.
2. Sort each pair.
3. Merge the sorted pairs into a single list.
4. Insert any remaining elements into the merged list.*/

// FORD-JOHSON ALGORITM
void merge(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> leftVec(vec.begin() + left, vec.begin() + mid + 1);
    std::vector<int> rightVec(vec.begin() + mid + 1, vec.begin() + right + 1);

    size_t leftIndex = 0;
    size_t rightIndex = 0;
    size_t index = left;

    while (leftIndex < leftVec.size() && rightIndex < rightVec.size()) {
        if (leftVec[leftIndex] < rightVec[rightIndex]) {
            vec[index++] = leftVec[leftIndex++];
        } else {
            vec[index++] = rightVec[rightIndex++];
        }
    }

    while (leftIndex < leftVec.size()) {
        vec[index++] = leftVec[leftIndex++];
    }

    while (rightIndex < rightVec.size()) {
        vec[index++] = rightVec[rightIndex++];
    }
}

void fordJohnsonSort(std::vector<int>& vec, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    fordJohnsonSort(vec, left, mid);
    fordJohnsonSort(vec, mid + 1, right);

    merge(vec, left, mid, right);
}

void mergeInsertSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    fordJohnsonSort(vec, 0, vec.size() - 1);
}

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
        auto start = std::chrono::high_resolution_clock::now();

        // Parse input sequence
        std::vector<int> vec = parseInput(argc, argv);
        // Copy sequence to deque for second sorting
        //std::deque<int> deq(vec.begin(), vec.end());

        std::cout << "Before: ";
        printContainer(vec);

        
        mergeInsertSort(vec);


/*         start = std::chrono::high_resolution_clock::now();
        mergeInsertSort(deq);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> durationDeque = end - start; */

        std::cout << "After: ";
        printContainer(vec);

            auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> durationVector = end - start;

        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << durationVector.count() << " us" << std::endl;
        //std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << durationDeque.count() << " us" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
