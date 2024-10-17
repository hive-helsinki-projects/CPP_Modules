/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:38:36 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 22:06:30 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm parameter constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other)
: AForm(other)
, target(other.target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

/* PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
    AForm::operator=(other);
    target = other.target;
    return *this;
} */

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

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
