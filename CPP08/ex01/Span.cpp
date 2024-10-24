/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:23:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/23 15:35:57 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


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

/* ADD NUMBER */
void Span::addNumber(int number) {
    if (numbers.size() < maxSize) {
        numbers.push_back(number);
    } else {
        throw std::runtime_error("Span is full");
    }
}

int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to calculate span");
    }
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    int min = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size() - 1; i++) {
        if (sorted[i + 1] - sorted[i] < min) {
            min = sorted[i + 1] - sorted[i];
        }
    }
    return min;
}

int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to calculate span");
    }
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}


