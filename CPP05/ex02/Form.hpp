/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:36:38 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/16 09:45:37 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

#define LOWEST 150
#define HIGHEST 1

class Bureaucrat;

class Form {
private:
    std::string const name;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExecute;
public:
    Form();
    Form(const std::string& n, int gradeToSign, int gradeToExecute);
    Form(Form const& other);
    Form& operator=(Form const& other);
    ~Form();

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    // Sign and execute form
    void beSigned(const Bureaucrat& b);
    
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif