/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:29:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/14 22:22:56 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class Bureaucrat {
private:
    std::string const name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string& n, int grade);
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
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:        
            const char* what() const throw();
    };
};

// Overload << operator to print Bureaucrat object
std::ostream& operator<<(std::ostream& os, Bureaucrat const& obj);

#endif