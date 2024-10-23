/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:23:13 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/23 14:19:48 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

template <typename T>
class Array {
private:
    T *array; // Array of type T
    unsigned int arraySize; // Size of the array
public:
    Array(); // Default constructor: creates an empty array
    Array(unsigned int n); // Constructor: creates an array of size n
    Array(const Array&); // Copy constructor
    Array &operator=(const Array&); // Assignment operator
    ~Array(void); // Destructor
    
    T &operator[](unsigned int n); // Subscript operator
    
    unsigned int size() const; // Size function
};

#endif