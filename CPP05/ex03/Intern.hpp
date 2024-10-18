/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:10:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/18 09:10:06 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

#define BLUE "\033[34m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

class Intern {
private:
    typedef AForm* (*formCreator)(std::string const& target);
    struct FormType {
        std::string name;
        formCreator creator;
    };
    static AForm* createShrubberyCreationForm(std::string const& target);
    static AForm* createRobotomyRequestForm(std::string const& target);
    static AForm* createPresidentialPardonForm(std::string const& target);
    static const FormType formTypes[3];
public:
    Intern();
    Intern(Intern const& other) = delete;
    Intern& operator=(Intern const& other) = delete;
    ~Intern();

    AForm* makeForm(std::string const& form, std::string const& target);
};

#endif