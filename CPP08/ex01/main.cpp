/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:36:33 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/24 13:55:13 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main() {

    // Test with 5 numbers
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Adding more numbers in one call using a range
        std::vector<int> numbers = {20, 30, 40, 50};
        Span sp2(10);
        sp2.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test with 10000 numbers
    try {
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