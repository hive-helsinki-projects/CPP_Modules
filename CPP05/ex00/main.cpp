/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:03:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 09:15:27 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

    try {
        std::cout << BLUE << "[BUREAUCRAT ALICE]" << RESET << std::endl;
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
            
        std::cout << BLUE << "\n[BUREAUCRAT BOB]" << RESET << std::endl;
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;

        std::cout << BLUE << "\n[BUREAUCRAT CHARLIE]" << RESET << std::endl;
        // This will throw an exception
        Bureaucrat b3("Charlie", 151);
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception " << e.what() << std::endl;
    }

    try {
        std::cout << BLUE << "\n[BUREAUCRAT DAVE]" << RESET << std::endl;
        Bureaucrat b4("Dave", 1);
        b4.incrementGrade(); // This will throw an exception
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception " << e.what() << std::endl;
    }

    try {
        std::cout << BLUE << "\n[BUREAUCRAT EVE]" << RESET << std::endl;
        Bureaucrat b5("Eve", 150);
        b5.decrementGrade(); // This will throw an exception
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception " << e.what() << std::endl;
    }

    return 0;
}
