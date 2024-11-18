# Cpp09: STL - Summary of Learning

## ex00: Bitcoin Exchange
### Objective
Implement a program to simulate a Bitcoin exchange.

### Key Concepts
- **File I/O**: Reading from and writing to files using file streams (`std::ifstream`, `std::ofstream`).
- **Data Parsing**: Parsing and processing data from files.
- **Maps**: Using `std::map` to store and retrieve exchange rates efficiently.
- **Error Handling**: Managing errors related to file operations and data parsing.

### Example
Reading historical Bitcoin prices from a file, storing them in a `std::map`, and allowing the user to query the exchange rate for specific dates.

## ex01: Reverse Polish Notation
### Objective
Implement a calculator that evaluates expressions in Reverse Polish Notation (RPN).

### Key Concepts
- **Stacks**: Using `std::stack` to manage operands and operators in RPN evaluation.
- **Algorithm Implementation**: Implementing the RPN evaluation algorithm.
- **Exception Handling**: Handling invalid expressions and division by zero.

### Example
Evaluating expressions like `3 4 + 2 * 7 /` using a stack to manage intermediate results.

## ex02: PmergeMe
### Objective
Implement a program to sort a sequence of positive integers using the Ford-Johnson merge-insert sort algorithm.

### Key Concepts
- **Templates**: Writing generic functions and classes using templates.
- **STL Containers**: Using `std::vector` and `std::deque` to store and sort integers.
- **Algorithms**: Implementing the merge-insert sort algorithm.
- **Performance Measurement**: Measuring and comparing the execution time of sorting operations.
- **Error Handling**: Validating input and handling errors gracefully.

### Example
Sorting a sequence of integers provided as command-line arguments and displaying the sorted sequence along with the time taken for sorting using both `std::vector` and `std::deque`.

## Practical Application
### Project: PmergeMe
#### Requirements
- Use two different STL containers (e.g., `std::vector` and `std::deque`).
- Handle at least 3000 integers.
- Display unsorted and sorted sequences.
- Measure and display the time taken for sorting with each container.

#### Implementation
- Divide the code into header (`PmergeMe.hpp`), implementation (`PmergeMe.cpp`), and main (`main.cpp`) files.
- Update the Makefile to compile the program.
- Ensure proper error handling and input validation.

By completing these exercises, you will gain a solid understanding of C++ STL, including file I/O, data structures like maps and stacks, algorithm implementation, and performance measurement. These skills are essential for writing efficient and maintainable C++ programs that leverage the power of the STL.