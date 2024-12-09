/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:36:33 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/09 17:09:54 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void Span::print(std::ostream& os) const {
    os << "Adding [";
    for (size_t i = 0; i < numbers.size(); ++i) {
        os << numbers[i];
        if (i < numbers.size() - 1) {
            os << ", ";
        }
    }
    os << "]\n";
}

int main() {

    // Test with 5 numbers
    try {
        std::cout << YELLOW "Test 1" RESET << std::endl;
        Span sp = Span(5);
        sp.print(std::cout);
        sp.addNumber(6);
        sp.print(std::cout);
        sp.addNumber(3);
        sp.print(std::cout);
        sp.addNumber(17);
        sp.print(std::cout);
        sp.addNumber(9);
        sp.print(std::cout);
        sp.addNumber(11);
        sp.print(std::cout);
        
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test with adding more numbers in one call using a range
    try {
        // Adding more numbers in one call using a range
        std::cout << YELLOW "Test 2" RESET << std::endl;
        std::vector<int> numbers = {20, 30, 40, 50};
        Span sp(10);
        sp.addNumbers(numbers.begin(), numbers.end());

        sp.print(std::cout);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test with 10000 numbers
    try {
        std::cout << YELLOW "Test 3" RESET << std::endl;
        Span sp = Span(10000);
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(i);
        }
        
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}