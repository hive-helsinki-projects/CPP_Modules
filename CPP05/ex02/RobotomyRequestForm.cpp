/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:57:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 22:06:55 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm parameter constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
: target(other.target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

/* RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
    AForm::operator=(other);
    target = other.target;
    return *this;
} */

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
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
