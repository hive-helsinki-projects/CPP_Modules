/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:03:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/15 22:58:17 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
    
    Bureaucrat b1("Bureaucrat 1", 1);
    Bureaucrat b2("Bureaucrat 2", 150);
    Form f1("Form 1", 1, 1);
    Form f2("Form 2", 150, 150);

    std::cout << BLUE << "\n[BUREAUCRAT 1]" << RESET << std::endl;
    std::cout << b1 << std::endl;
    try {
        b1.incrementGrade();
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception " << RED << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n[BUREAUCRAT 2]" << RESET << std::endl;
    std::cout << b2 << std::endl;
    try {
        b2.decrementGrade();
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception " << RED << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "\n[FORM 1]" << RESET << std::endl;
    std::cout << f1 << std::endl;
    std::cout << BLUE << "\n[FORM 2]" << RESET << std::endl;
    std::cout << f2 << std::endl;
    try {
        f1.beSigned(b1);
    } catch (Form::GradeTooLowException& e) {
        std::cout << "Exception " << RED << e.what() << RESET << std::endl;
    }

    try {
        f2.beSigned(b2);
    } catch (Form::GradeTooHighException& e) {
        std::cout << "Exception " << RED << e.what() << RESET << std::endl;
    }

    return 0;
}
