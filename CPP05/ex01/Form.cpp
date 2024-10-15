/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:42:36 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/15 22:46:14 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* CONSTRUCTORS, DESTRUCTORS, OPERATORS */
Form::Form()
: name("default")
, isSigned(false)
, gradeToSign(LOWEST)
, gradeToExecute(LOWEST)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& n, int gradeToSign, int gradeToExecute)
: name(n)
, isSigned(false)
, gradeToSign(gradeToSign)
, gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form const& other)
: name(other.name)
, isSigned(other.isSigned)
, gradeToSign(other.gradeToSign)
, gradeToExecute(other.gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(Form const& other)
{
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
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

void Form::signForm(const Bureaucrat& b)
{
    try
    {
        beSigned(b);
    }
    catch (std::exception& e)
    {
        std::cout << b.getName() << " cannot sign " << name << " because " << e.what() << std::endl;
    }
}

/* EXCEPTIONS */
const char* Form::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

/* OVERLOADS */
std::ostream& operator<<(std::ostream& os, Form const& form)
{
    os << "Form: " << form.getName() << ", signed: " << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
    return os;
}
