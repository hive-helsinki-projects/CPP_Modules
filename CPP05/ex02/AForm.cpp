/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:42:36 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 20:19:52 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* CONSTRUCTORS, DESTRUCTORS, OPERATORS */
AForm::AForm()
: name("default")
, isSigned(false)
, gradeToSign(LOWEST)
, gradeToExecute(LOWEST)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const& n, int gradeToSign, int gradeToExecute)
: name(n)
, isSigned(false)
, gradeToSign(gradeToSign)
, gradeToExecute(gradeToExecute)
{
    if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
    {
        throw GradeTooHighException();
    }
    if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
    {
        throw GradeTooLowException();
    }
    std::cout << "AForm parameterized constructor called" << std::endl;
}

AForm::AForm(AForm const& other)
: name(other.name)
, isSigned(other.isSigned)
, gradeToSign(other.gradeToSign)
, gradeToExecute(other.gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

/* GETTERS */
std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

/* METHODS */
void AForm::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() > gradeToSign)
    {
        throw GradeTooLowException();
    }
    isSigned = true;
}

/* EXCEPTIONS */
const char* AForm::GradeTooHighException::what() const noexcept
{
    return (RED "Grade is too high" RESET);
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return (RED "Grade is too low" RESET);
}

const char* AForm::FormNotSignedException::what() const noexcept
{
    return (RED "Form is not signed" RESET);
}

/* OVERLOADS */
std::ostream& operator<<(std::ostream& os, AForm const& form) {
    os << "AForm: " << GREEN << form.getName() << RESET
       << ", signed: " << GREEN << (form.getIsSigned() ? "yes" : "no") << RESET
       << ", grade to sign: " << GREEN << form.getGradeToSign() << RESET
       << ", grade to execute: " << GREEN << form.getGradeToExecute() << RESET;
    return os;
}