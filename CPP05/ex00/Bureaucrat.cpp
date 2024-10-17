/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:35:28 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 19:59:43 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const int LOWEST = 150;
const int HIGHEST = 1;

/* CONSTRUCTORS AND DESTRUCTOR */
Bureaucrat::Bureaucrat()
: name("Default")
, grade(LOWEST)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& n, int grade)
: name(n)
, grade(grade)
{
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    if (grade < HIGHEST) throw GradeTooHighException();
    if (grade > LOWEST) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& other)
: name(other.name)
, grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
    if (other.grade < HIGHEST) throw GradeTooHighException();
    if (other.grade > LOWEST) throw GradeTooLowException();
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
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
    std::cout << GREEN << "++Incrementing one grade ... " << RESET << std::endl;
    if (grade <= HIGHEST) {
        throw Bureaucrat::GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade() {
    std::cout << GREEN << "--Decrementing one grade ... " << RESET << std::endl;
    if (grade >= LOWEST) {
        throw Bureaucrat::GradeTooLowException();
    }
    grade++;
}

/* EXCEPTION CLASSES */
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return (RED "Grade is too high!" RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return (RED "Grade is too low!" RESET);
}

/* OVERLOAD << OPERATOR */
std::ostream& operator<<(std::ostream& os, Bureaucrat const& obj) {
    os << obj.getName() << ", bureaucrat grade " << BLUE << obj.getGrade() << RESET;
    return os;
}
