/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:23:18 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/09 16:56:21 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>   // distance, sort, max, min
# include <vector>      // vector
# include <stdexcept>   // out_of_range, logic_error


# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define RESET   "\033[0m"

class Span {
private:
    unsigned int maxSize;
    std::vector<int> numbers;
public:
    Span();
    Span(unsigned int N);
    Span(const Span&);
    Span& operator=(const Span&);
    ~Span();

    // Add single number to the Span
    void addNumber(int number);
    
    // Add range of numbers to the Span
    template <typename T>
    void addNumbers(T begin, T end) {
        if (numbers.size() + std::distance(begin, end) > maxSize) {
            throw std::out_of_range("Span is full");
        }
        numbers.insert(numbers.end(), begin, end);
    }
    
    // Calculate the shortest span and longest span between numbers
    int shortestSpan() const;
    int longestSpan() const;

    void print(std::ostream& os) const;
};
