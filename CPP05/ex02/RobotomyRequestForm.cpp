/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:57:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/18 09:01:07 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/* CONSTRUCTOR AND DESTRUCTOR */
RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm parameter constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

/* METHOD EXECUTE */
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    srand(time(0)); // Seed the random number generator
    // Check if the form is signed
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    // Check if executor has the right grade to execute the form
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    std::cout << "*drilling noises*" << std::endl;
    int randomNumber = rand();
    int outcome = randomNumber % 2;
    std::cout << "Random number: " << randomNumber
            << ", Outcome (1=Success, 0=Fail): " << outcome << std::endl;
    if (outcome) {
        std::cout << target << " has been robotomized successfully 50% of the time" << std::endl;
    } else {
        std::cout << target << " failed" << std::endl;
    }
}
