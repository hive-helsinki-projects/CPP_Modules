/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:25:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/23 14:08:12 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

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

template <typename T>
T &Array<T>::operator[](unsigned int n) {
    if (n >= arraySize) {
        throw std::out_of_range("Index out of range");
    }
    return array[n];
}

template <typename T>
unsigned int Array<T>::size() const {
    return arraySize;
}