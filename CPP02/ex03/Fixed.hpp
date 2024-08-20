/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:37:16 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 18:59:43 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int fixedPointValue;
    static const int fractionalBits = 8; // Number of fractional bits

public:
    // Class definition
    Fixed(); // Default constructor
    Fixed(const Fixed& other); // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed(); // Destructor

    // Float definition
    Fixed(const float value);
    float toFloat(void) const; // Convert to float

    // Comparison operators
    bool operator>(const Fixed& f) const;
    bool operator<(const Fixed& f) const;
    bool operator>=(const Fixed& f) const;
    bool operator<=(const Fixed& f) const;
    bool operator==(const Fixed& f) const;
    bool operator!=(const Fixed& f) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& f) const;
    Fixed operator-(const Fixed& f) const;
    Fixed operator*(const Fixed& f) const;
    Fixed operator/(const Fixed& f) const;

    // Increment/Decrement operators
    Fixed& operator++(); // Pre-increment
    Fixed operator++(int); // Post-increment
    Fixed& operator--(); // Pre-decrement
    Fixed operator--(int); // Post-decrement

    // Overloaded member functions
    static Fixed& min(Fixed& f1, Fixed& f2);
    static const Fixed& min(const Fixed& f1, const Fixed& f2);
    static Fixed& max(Fixed& f1, Fixed& f2);
    static const Fixed& max(const Fixed& f1, const Fixed& f2);
    
    // Method to return the absolute value
    Fixed abs() const;
};

// Overload of the insertation (<<) operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif