/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:03:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 19:54:49 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << BLUE << "\n[STATUS OF FORMS]" << std::endl << RESET;
        // Create forms and print status
        Form formA("FORM A", 2, 50);
        Form formB("FORM B", 150, 50);
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
    
        std::cout << BLUE << "\n[BUREAUCRAT ALICE]" << RESET << std::endl;
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        // Alice sign Form A        
        b1.signForm(formA); // Should succeed
            
        std::cout << BLUE << "\n[BUREAUCRAT BOB]" << RESET << std::endl;
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;
        // Bob sign Form A & B
        b2.signForm(formA); // Should fail
        b2.signForm(formB); // Should succeed

        std::cout << BLUE << "\n[STATUS OF FORMS]" << std::endl << RESET;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << BLUE << "\n[DESTRUCTOR]" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }
 
    return 0;
}