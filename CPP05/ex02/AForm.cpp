/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:42:36 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 11:23:53 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* CONSTRUCTORS, DESTRUCTORS, OPERATORS */
AForm::AForm()
: name("default")
, isSigned(false)
, gradeToSign(LOWEST)
, gradeToExecute(LOWEST)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& n, int gradeToSign, int gradeToExecute)
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

AForm& AForm::operator=(AForm const& other)
{
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
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
void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
    {
        throw GradeTooLowException();
    }
    isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (!isSigned)
    {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > gradeToExecute)
    {
        throw GradeTooLowException();
    }
    action();
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
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm: " << form.getName() << ", signed: " << GREEN << (form.getIsSigned() ? "yes" : "no") << RESET
       << ", grade to sign: " << GREEN << form.getGradeToSign() << RESET
       << ", grade to execute: " << GREEN << form.getGradeToExecute() << RESET;
    return os;
}