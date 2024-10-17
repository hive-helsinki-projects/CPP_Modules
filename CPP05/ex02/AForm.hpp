/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:36:38 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 22:31:29 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
private:
    std::string const name;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExecute;
public:
    AForm() = delete;
    AForm(std::string const& n, int gradeToSign, int gradeToExecute);
    AForm(AForm const& other) = delete;
    AForm& operator=(AForm const& other) = delete;
    virtual ~AForm();

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    // Sign AForm
    void beSigned(Bureaucrat const& b);

    // Pure virtual method
    virtual void execute(Bureaucrat const& executor) const = 0;
    
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

std::ostream& operator<<(std::ostream& os, AForm const& form);

#endif