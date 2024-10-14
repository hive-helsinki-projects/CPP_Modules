/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:03:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/14 22:05:34 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;

        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;

        // This will throw an exception
        Bureaucrat b3("Charlie", 151);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Dave", 1);
        b4.incrementGrade(); // This will throw an exception
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("Eve", 150);
        b5.decrementGrade(); // This will throw an exception
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
