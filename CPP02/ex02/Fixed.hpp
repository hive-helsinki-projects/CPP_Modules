/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:37:16 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 05:40:13 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
private:
    int fixedPointValue;
    static const int fractionalBits = 8; // Number of fractional bits

public:
    Fixed(); // Default constructor
    Fixed(const Fixed& other); // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed(); // Destructor

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
};

// Overload of the insertation operators 
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif