/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:38:36 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 22:32:17 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/* CONSTRUCTOR AND DESTRUCTOR */
PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm parameter constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

/* METHOD EXECUTE */
void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    // Check if the form is signed
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    // Check if executor has the right grade to execute the form
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
