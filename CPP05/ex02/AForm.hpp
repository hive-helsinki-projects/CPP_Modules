/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:36:38 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 13:11:08 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

#define LOWEST 150
#define HIGHEST 1

class Bureaucrat;

class AForm {
private:
    std::string const name;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExecute;
public:
    AForm();
    AForm(const std::string& n, int gradeToSign, int gradeToExecute);
    AForm(AForm const& other);
    AForm& operator=(AForm const& other);
    virtual ~AForm();

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    // Sign and execute AForm
    void beSigned(const Bureaucrat& b);

    // Pure virtual method
    virtual void execute(const Bureaucrat& executor) const = 0;
    
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
    class FormNotSignedException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
};

std::ostream& operator<<(std::ostream& os, AForm const& AForm);

#endif