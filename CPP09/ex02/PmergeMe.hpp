/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:23:03 by lkilpela          #+#    #+#             */
/*   Updated: 2025/02/24 18:54:34 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <chrono>
#include <algorithm>

// Prototype
void processSequence(int argc, char **argv);

/* TEMPLATE */

// Function to check if a container is sorted
template <typename T>
bool isSorted(const T& container) {
    return std::is_sorted(container.begin(), container.end());
}

// Function to merge two sorted parts of a container
template <typename T>
void merge(T& container, int left, int mid, int right) {
    T leftPart(container.begin() + left, container.begin() + mid + 1);
    T rightPart(container.begin() + mid + 1, container.begin() + right + 1);

    size_t leftIndex = 0;
    size_t rightIndex = 0;
    size_t index = left;

    while (leftIndex < leftPart.size() && rightIndex < rightPart.size()) {
        if (leftPart[leftIndex] < rightPart[rightIndex]) {
            container[index++] = leftPart[leftIndex++];
        } else {
            container[index++] = rightPart[rightIndex++];
        }
    }

    while (leftIndex < leftPart.size()) {
        container[index++] = leftPart[leftIndex++];
    }

    while (rightIndex < rightPart.size()) {
        container[index++] = rightPart[rightIndex++];
    }
}

// Function to sort a container using merge sort
template <typename T>
void fordJohnsonSort(T& container, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    
    fordJohnsonSort(container, left, mid);
    fordJohnsonSort(container, mid + 1, right);

    merge(container, left, mid, right);
}

template <typename T>
void mergeInsertSort(T& container) {
    if (container.size() <= 1) return;

    fordJohnsonSort(container, 0, container.size() - 1);
}

// Function to measure the time it takes to sort a container
template <typename T>
double measureSortTime(T& container) {
    auto start = std::chrono::high_resolution_clock::now();
    mergeInsertSort(container);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;
    return duration.count();
}

// Function to print a container
template <typename Container>
void printContainer(const Container& container) {
    if (container.empty()) {
        throw std::runtime_error("Error: container is empty");
    }
    if (container.size() > 50) {
        for (size_t i = 0; i < 5; ++i) {
            std::cout << container[i] << " ";
        }
        std::cout << "[...]";
    } else {
        for (const auto& elem : container) {
            std::cout << elem << " ";
        }
    }
    std::cout << std::endl;
}
