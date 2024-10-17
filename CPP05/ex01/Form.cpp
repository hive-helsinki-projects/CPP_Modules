/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:42:36 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 22:27:42 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const int LOWEST = 150;
const int HIGHEST = 1;

/* CONSTRUCTORS, DESTRUCTORS, OPERATORS */
Form::Form(const std::string& n, int gradeToSign, int gradeToExecute)
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
    std::cout << "Form parameterized constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

/* GETTERS */
std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

/* METHODS */
void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
    {
        throw GradeTooLowException();
    }
    isSigned = true;
}

/* EXCEPTIONS */
const char* Form::GradeTooHighException::what() const noexcept
{
    return (RED "Grade is too high" RESET);
}

const char* Form::GradeTooLowException::what() const noexcept
{
    return (RED "Grade is too low" RESET);
}

/* OVERLOADS */
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << GREEN << form.getName() << RESET
       <<  ", signed: " << GREEN << (form.getIsSigned() ? "yes" : "no") << RESET
       << ", grade to sign: " << GREEN << form.getGradeToSign() << RESET
       << ", grade to execute: " << GREEN << form.getGradeToExecute() << RESET;
    return os;
}