/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:03:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 15:54:58 by lkilpela         ###   ########.fr       */
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

void test1()
{
    try {
        // Status of forms
        std::cout << BLUE << "\n[1STATUS OF FORMS]" << RESET << std::endl;
        ShrubberyCreationForm form("Shrubbery");
        RobotomyRequestForm form1("Robotomy");
        PresidentialPardonForm form2("Presidential");
        printFormStatus(form, form1, form2);

        // Bureaucrat Alice
        std::cout << BLUE << "\n[1.BUREAUCRAT ALICE]" << RESET << std::endl;
        Bureaucrat alice("Alice", 1); // Grade 1 (highest)
        std::cout << alice << std::endl;
        std::cout << GREEN << alice.getName() << " is signning the form..." << std::endl << RESET;        
        
        // Form Shrubbery
        //alice.signForm(form); // Form is not signed, throws exception & execution fails
        alice.signForm(form); // Form is signed
        alice.executeForm(form);  // Should succeed & a file should be created    
        // Form Robotomy
        alice.signForm(form1); // Form is signed
        alice.executeForm(form1); // Should succeed
        // Form Presidential
        alice.signForm(form2); // Form is signed
        alice.executeForm(form2); // Should succeed

        // Print status of forms
        std::cout << std::endl;
        printFormStatus(form, form1, form2);

        std::cout << BLUE << "\n[1. DESTRUCTOR]" << std::endl << RESET;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void test2()
{
    try {
        // Status of forms
        std::cout << BLUE << "\n[2. STATUS OF FORMS]" << RESET << std::endl;
        ShrubberyCreationForm form("Shrubbery");
        RobotomyRequestForm form1("Robotomy");
        PresidentialPardonForm form2("Presidential");
        printFormStatus(form, form1, form2);

        // Bureaucrat Bob
        std::cout << BLUE << "\n[2. BUREAUCRAT BOB]" << RESET << std::endl;
        Bureaucrat bob("Bob", 137); // Grade 150 (lowest)
        std::cout << bob << std::endl;
        std::cout << GREEN << bob.getName() << " is signning the form..." << std::endl << RESET;        
        
        // Form Shrubbery
        bob.signForm(form); // Should fail, throws exception
        bob.executeForm(form);  // Should fail, throws exception      
        // Form Robotomy
        bob.signForm(form1); // Should fail, throws exception
        bob.executeForm(form1); // Should fail, throws exception
        // Form Presidential
        bob.signForm(form2); // Should fail, throws exception
        bob.executeForm(form2); // Should fail, throws exception

        // Print status of forms
        std::cout << std::endl;
        printFormStatus(form, form1, form2);

        std::cout << BLUE << "\n[2. DESTRUCTOR]" << std::endl << RESET;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
int main() {
    srand(time(0)); // Seed the random number generator
    test1();
    test2();
    return 0;
}