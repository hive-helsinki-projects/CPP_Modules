/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:10:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 15:26:02 by lkilpela         ###   ########.fr       */
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

class Intern {
private:
    typedef AForm* (*formCreator)(const std::string& target);
    struct FormType {
        std::string name;
        formCreator creator;
    };
    static AForm* createShrubberyCreationForm(const std::string& target);
    static AForm* createRobotomyRequestForm(const std::string& target);
    static AForm* createPresidentialPardonForm(const std::string& target);
    static const FormType formTypes[3];
public:
    Intern();
    Intern(Intern const& other);
    Intern& operator=(Intern const& other);
    ~Intern();

    AForm* makeForm(const std::string& form, const std::string& target);
};

#endif