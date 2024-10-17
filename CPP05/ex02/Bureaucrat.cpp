/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:35:28 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 22:32:07 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* CONSTRUCTOR AND DESTRUCTOR */
Bureaucrat::Bureaucrat(std::string const& n, int grade)
: name(n)
, grade(grade)
{
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    if (grade < HIGHEST) throw GradeTooHighException();
    if (grade > LOWEST) throw GradeTooLowException();
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

/* METHOD TO SIGN FORM */
void Bureaucrat::signForm(AForm& form) {
    std::cout << GREEN << "\n[" << form.getName() << "]" << std::endl << RESET;
    std::cout << "---------------------------------" << std::endl;
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << name << " couldn't sign "
                << form.getName()
                << " because " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << name << " couldn't sign "
                << form.getName()
                << " because " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << name << " couldn't sign "
                << form.getName()
                << " because " << e.what() << std::endl;
    }
}

/* METHOD TO EXECUTE FORM */
void Bureaucrat::executeForm(AForm const& form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << name << " couldn't execute "
                << form.getName()
                << " because " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << name << " couldn't execute "
                << form.getName()
                << " because " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << name << " couldn't execute "
                << form.getName()
                << " because " << e.what() << std::endl;
    }
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
