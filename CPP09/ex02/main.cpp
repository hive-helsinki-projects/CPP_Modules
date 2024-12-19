#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <sstream>

int main(int argc, char **argv) {
    PmergeMe pmergeMe;
    pmergeMe.processSequence(argc, argv);
    return 0;
}