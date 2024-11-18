#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

// Function to print a container
template <typename Container>
void printContainer(const Container& container);

// Merge-insert sort algorithm for std::vector
void mergeInsertSortVector(std::vector<int>& vec);

// Merge-insert sort algorithm for std::deque
void mergeInsertSortDeque(std::deque<int>& deq);

#endif // PMERGEME_HPP