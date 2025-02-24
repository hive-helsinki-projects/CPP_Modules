/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:22:38 by lkilpela          #+#    #+#             */
/*   Updated: 2025/02/24 19:31:42 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    try {
        if (argc < 2) {
            throw std::invalid_argument("Usage: ./PmergeMe n1 n2 n3 [...]");
        }
        processSequence(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}