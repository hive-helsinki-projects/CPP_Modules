/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:35:28 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/15 22:26:48 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Bureaucrat::Bureaucrat()
: name("Default")
, grade(LOWEST)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& n, int grade)
: name(n)
, grade(grade)
{
    std::cout << "Parameterized constructor called" << std::endl;
    if (grade < HIGHEST) throw GradeTooHighException();
    if (grade > LOWEST) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& other)
: name(other.name)
, grade(other.grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
    if (other.grade < HIGHEST) throw GradeTooHighException();
    if (other.grade > LOWEST) throw GradeTooLowException();
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}

/* GETTERS */
std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

/* INCREMENT AND DECREMENT GRADE */
void Bureaucrat::incrementGrade() {
    if (grade - 1 < HIGHEST) {
        throw Bureaucrat::GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > LOWEST) {
        throw Bureaucrat::GradeTooLowException();
    }
    grade++;
}

/* EXCEPTION CLASSES */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return (RED "Grade is too high!" RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return (RED "Grade is too low!" RESET);
}

/* OVERLOAD << OPERATOR */
std::ostream& operator<<(std::ostream& os, Bureaucrat const& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}
