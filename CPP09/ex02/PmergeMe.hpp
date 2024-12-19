#pragma once

#include <vector>
#include <deque>
#include <iostream>

// Prototype
void processSequence(int argc, char **argv);


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
