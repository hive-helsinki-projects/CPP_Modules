/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:03:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/16 15:20:37 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        
        Bureaucrat alice("Alice", 2);
        Bureaucrat bob("Bob", 149);
        Form formA("House Loan Contract", 2, 50);
        Form formB("Work Contract", 150, 50);

        std::cout << BLUE << "\n[BUREAUCRAT ALICE]" << RESET << std::endl;
        alice.signForm(formA); // Should succeed
        std::cout << BLUE << "\n[BUREAUCRAT BOB]" << RESET << std::endl;
        bob.signForm(formA);   // Should fail
        bob.signForm(formB);   // Should succeed

        std::cout << BLUE << "\n[STATUS OF FORMS]" << std::endl << RESET;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
           std::cout << BLUE << "\nCalling destructor" << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

 
    return 0;
}