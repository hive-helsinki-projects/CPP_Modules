/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:23:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/09 16:36:36 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>      // numeric_limits

/* CONSTRUCTORS, DESTRUCTOR, OPERATOR= */
Span::Span()
: maxSize(0) {}

Span::Span(unsigned int N)
: maxSize(N) {}

Span::Span(const Span& other)
: maxSize(other.maxSize) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        maxSize = other.maxSize;
    }
    return *this;
}

Span::~Span() {}

/* ADD SINGLE NUMBER */
void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw std::out_of_range("Span is full");
    }
    numbers.push_back(number);
}

/* FIND SHORTEST SPAN (MIN DISTANCE BETWEEN TWO CONSECUTIVE NUMBERS) 
** Given numbers : 6, 3, 17, 9, 11
** Sorted numbers: 3, 6, 9, 11, 17
** Span1 = 6 - 3 = 3
** Span2 = 9 - 6 = 3
** Span3 = 11 - 9 = 2
** Span4 = 17 - 11 = 6
** Shortest span = 2
*/
int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to calculate span");
    }
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    int min = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); i++) {
        int span = sorted[i] - sorted[i - 1];
        if (span < min) {
            min = span;
        }
    }
    return min;
}

/* FIND LONGEST SPAN (MAX DISTANCE BETWEEN SMALLEST AND LARGEST NUMBERS)
** Given numbers : 6, 3, 17, 9, 11
** Sorted numbers: 3, 6, 9, 11, 17
** Min = 3, Max = 17
** Longest span = 17 - 3 = 14
*/
int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to calculate span");
    }
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}


