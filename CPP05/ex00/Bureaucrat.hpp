/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:29:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 19:59:39 by lkilpela         ###   ########.fr       */
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

class Bureaucrat {
private:
    std::string const name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(std::string const& n, int grade);
    Bureaucrat(Bureaucrat const& other);
    Bureaucrat& operator=(Bureaucrat const& other);
    ~Bureaucrat();
    
    // Getters
    std::string getName() const;
    int getGrade() const;

    // Increment and decrement grade
    void incrementGrade();
    void decrementGrade();
    
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