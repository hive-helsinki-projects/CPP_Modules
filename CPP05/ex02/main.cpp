/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:03:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 12:38:17 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    srand(time(0)); // Seed the random number generator

    try {
        std::cout << BLUE << "\n[BUREAUCRAT ALICE]" << RESET << std::endl;
        Bureaucrat alice("Alice", 1); // Grade 1 (highest)
        std::cout << alice << std::endl;
        
        std::cout << BLUE << "\n[FORM. ROBOTOMY]" << std::endl << RESET;
        RobotomyRequestForm form("Robotomy");
        std::cout << form << std::endl;
        alice.signForm(form); // Should succeed
        alice.executeForm(form);  // Perform the action
        
        std::cout << BLUE << "\n[FORM. SHRUBBERY]" << std::endl << RESET;
        ShrubberyCreationForm form2("Shrubbery");
        std::cout << form2 << std::endl;
        alice.signForm(form2);
        alice.executeForm(form2);  // Perform the action
        alice.executeForm(form2);
        alice.executeForm(form2);
        
        std::cout << BLUE << "\n[FORM. PRESIDENTIAL]" << std::endl << RESET;
        PresidentialPardonForm form3("Presidential");
        std::cout << form3 << std::endl;
        alice.signForm(form3); // Should succeed
        alice.executeForm(form3);  // Perform the action

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}