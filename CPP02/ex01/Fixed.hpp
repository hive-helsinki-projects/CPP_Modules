/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:37:16 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/19 06:44:39 by lkilpela         ###   ########.fr       */
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

    Fixed(const int value);
    Fixed(const float value);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    float toFloat(void) const; // Convert to float
    int   toInt(void) const;   // Convert to int
};

// Overload of the insertation (<<) operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif