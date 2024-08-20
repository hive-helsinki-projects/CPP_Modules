/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:37:13 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 10:17:04 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : fixedPointValue(other.fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        fixedPointValue = other.fixedPointValue;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Comparison operators
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

// Arithmetic operators
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
    result.fixedPointValue =  fixedPointValue * f.fixedPointValue;
    return result;
}

Fixed Fixed::operator/(const Fixed& f) const {
    Fixed result;
    result.fixedPointValue =  fixedPointValue / f.fixedPointValue;
    return result;
}

// Pre-Increment/Decrement operators
Fixed& Fixed::operator++() {
    ++fixedPointValue;
    return *this;
}

Fixed& Fixed::operator--() {
    --fixedPointValue;
    return *this;
}

// Post-Increment/Decrement operators
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
// Static member functions

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