/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:37:13 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 19:00:33 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// 01. Member function Implementations

Fixed::Fixed() : fixedPointValue(0) {}

Fixed::Fixed(const Fixed& other) : fixedPointValue(other.fixedPointValue) {}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        fixedPointValue = other.fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed() {}

// 02. Float constructor & conversion

Fixed::Fixed(const float value) {
    fixedPointValue = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

float Fixed::toFloat(void) const {
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

// 03. Comparison operators

bool Fixed::operator>(const Fixed& f) const {
    return fixedPointValue > f.fixedPointValue;
}

bool Fixed::operator<(const Fixed& f) const {
    return fixedPointValue < f.fixedPointValue;
}

bool Fixed::operator>=(const Fixed& f) const {
    return fixedPointValue >= f.fixedPointValue;
}

bool Fixed::operator<=(const Fixed& f) const {
    return fixedPointValue <= f.fixedPointValue;
}

bool Fixed::operator==(const Fixed& f) const {
    return fixedPointValue == f.fixedPointValue;
}

bool Fixed::operator!=(const Fixed& f) const {
    return fixedPointValue != f.fixedPointValue;
}

// 04. Arithmetic operators
Fixed Fixed::operator+(const Fixed& f) const {
    Fixed result;
    result.fixedPointValue =  fixedPointValue + f.fixedPointValue;
    return result;
}

Fixed Fixed::operator-(const Fixed& f) const {
    Fixed result;
    result.fixedPointValue =  fixedPointValue - f.fixedPointValue;
    return result;
}

Fixed Fixed::operator*(const Fixed& f) const {
    Fixed result;
    result.fixedPointValue =  (fixedPointValue * f.fixedPointValue) / (1 << fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& f) const {
    Fixed result;
    result.fixedPointValue =  (fixedPointValue << fractionalBits) / f.fixedPointValue;
    return result;
}

// 05. Pre-Increment/Decrement operators

Fixed& Fixed::operator++() {
    ++fixedPointValue;
    return *this;
}

Fixed& Fixed::operator--() {
    --fixedPointValue;
    return *this;
}

// 06. Post-Increment/Decrement operators

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++fixedPointValue;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --fixedPointValue;
    return temp;
}

// 07. Static member functions

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
    return (f1 < f2) ? f1 : f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
    return (f1 < f2) ? f1 : f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
    return (f1 > f2) ? f1 : f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
    return (f1 > f2) ? f1 : f2;
}

// Overload operator (<<)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

// Method to return the absolute value
Fixed Fixed::abs() const {
    return Fixed(fixedPointValue < 0 ? -fixedPointValue : fixedPointValue);
}