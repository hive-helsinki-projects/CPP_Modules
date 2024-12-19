#pragma once

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
private:
    std::vector<int> vec;
    std::deque<int> deq;
public:
    PmergeMe() = default;
    PmergeMe(const PmergeMe&) = delete;
    PmergeMe& operator=(const PmergeMe&) = delete;
    ~PmergeMe() = default;

    std::vector<int> parseInput(int argc, char **argv);
    void mergeInsertSortVector(std::vector<int>& sequence);
    void mergeInsertSortDeque(std::deque<int>& sequence);
    void processSequence(int argc, char **argv);
};

// Function to print a container
template <typename Container>
void printContainer(const Container& container) {
    if (container.empty()) {
        throw std::runtime_error("Error: container is empty");
    }
    if (container.size() > 50) {
        for (size_t i = 0; i < 5; ++i) {
            std::cout << container[i] << " ";
        }
        std::cout << "[...]";
    } else {
        for (const auto& elem : container) {
            std::cout << elem << " ";
        }
    }
    std::cout << std::endl;
}


// Explicit instantiation of the template function
template void printContainer(const std::vector<int>& container);
template void printContainer(const std::deque<int>& container);
