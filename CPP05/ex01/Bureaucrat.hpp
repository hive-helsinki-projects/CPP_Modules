/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:29:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 22:26:47 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define BLUE "\033[34m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

class Form;

class Bureaucrat {
private:
    std::string const name;
    int grade;
public:
    Bureaucrat() = delete; // No implementation bc of const members
    Bureaucrat(std::string const& n, int grade);
    Bureaucrat(Bureaucrat const& other) = delete; // No implementation bc of const members
    Bureaucrat& operator=(Bureaucrat const& other) = delete; // No implementation bc of const members
    ~Bureaucrat();
    
    // Getters
    std::string getName() const;
    int getGrade() const;

    // Increment and decrement grade
    void incrementGrade();
    void decrementGrade();

    // Method to sign form
    void signForm(Form& form);
    
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

// Overload << operator to print Bureaucrat object
std::ostream& operator<<(std::ostream& os, Bureaucrat const& obj);

#endif