/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:23:18 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/24 13:44:44 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>   // sort, distance, max, min
# include <vector>      // vector
# include <stdexcept>   // runtime_error
# include <limits>      // numeric_limits

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
    void addNumber(T begin, T end);
    
    // Calculate the shortest span and longest span between numbers
    int shortestSpan() const;
    int longestSpan() const;
};

#endif