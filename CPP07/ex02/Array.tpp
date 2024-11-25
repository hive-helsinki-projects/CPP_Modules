/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:25:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/25 17:46:28 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

/* CONSTRUCTORS, DESTRUCTOR, ASSIGNMENT OPERATOR */
template <typename T>
Array<T>::Array()
: array(nullptr)
, arraySize(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
: array(new T[n])
, arraySize(n) {}

template <typename T>
Array<T>::Array(const Array& other)
: array(new T[other.arraySize])
, arraySize(other.arraySize) {
    for (unsigned int i = 0; i < arraySize; i++) {
        array[i] = other.array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] array;
        array = new T[other.arraySize];
        arraySize = other.arraySize;
        for (unsigned int i = 0; i < arraySize; i++) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array(void) {
    delete[] array;
}

/* SUBSCRIPT OPERATOR AND SIZE FUNCTION */
template <typename T>
T &Array<T>::operator[](unsigned int n) {
    if (n >= arraySize) {
        throw std::out_of_range("Index out of range");
    }
    return array[n];
}

template <typename T>
const T &Array<T>::operator[](unsigned int n) const {
    if (n >= arraySize) {
        throw std::out_of_range("Index out of range");
    }
    return array[n];
}


template <typename T>
unsigned int Array<T>::size() const {
    return arraySize;
}