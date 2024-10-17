/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:03:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 14:56:00 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void printFormStatus(const AForm& form, const AForm& form1, const AForm& form2) {
    std::cout << form << std::endl;
    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
}

int main() {
    srand(time(0)); // Seed the random number generator

    try {
      
        std::cout << BLUE << "\n[1. STATUS OF FORMS]" << RESET << std::endl;
        ShrubberyCreationForm form("Shrubbery");
        RobotomyRequestForm form1("Robotomy");
        PresidentialPardonForm form2("Presidential");
        printFormStatus(form, form1, form2);

        std::cout << BLUE << "\n[1.BUREAUCRAT ALICE]" << RESET << std::endl;
        Bureaucrat alice("Alice", 1); // Grade 1 (highest), grade 150 (lowest)
        std::cout << alice << std::endl;
        
        std::cout << GREEN << alice.getName() << " is signning the form..." << std::endl << RESET;        
        //alice.signForm(form); // Form is not signed, throws exception
        alice.executeForm(form);  // Should fail      

        alice.signForm(form1); // Form is signed
        alice.executeForm(form1); // Should succeed & a file should be created
        
        alice.signForm(form2); // Form is signed
        alice.executeForm(form2); // Should succeed

        std::cout << std::endl;
        printFormStatus(form, form1, form2);

        std::cout << BLUE << "\n[1. DESTRUCTOR]" << std::endl << RESET;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        
        std::cout << BLUE << "\n[2. STATUS OF FORMS]" << RESET << std::endl;
        ShrubberyCreationForm form("Shrubbery");
        RobotomyRequestForm form1("Robotomy");
        PresidentialPardonForm form2("Presidential");
        printFormStatus(form, form1, form2);

        std::cout << BLUE << "\n[2. BUREAUCRAT BOB]" << RESET << std::endl;
        Bureaucrat bob("Bob", 149); // Grade 1 (highest), grade 150 (lowest)
        std::cout << bob << std::endl;
        
        std::cout << GREEN << bob.getName() << " is signning the form..." << std::endl << RESET;        
        bob.signForm(form); // Should fail, throws exception
        bob.executeForm(form);  // Should fail, throws exception      

        bob.signForm(form1); // Should fail, throws exception
        bob.executeForm(form1); // Should fail, throws exception
        
        bob.signForm(form2); // Should fail, throws exception
        bob.executeForm(form2); // Should fail, throws exception

        std::cout << std::endl;
        printFormStatus(form, form1, form2);

        std::cout << BLUE << "\n[2. DESTRUCTOR]" << std::endl << RESET;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}