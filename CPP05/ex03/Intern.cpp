/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:12:34 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/18 09:10:22 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* CONSTRUCTOR, DESTRUCTOR */
Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

/* FORM CREATION FUNCTIONS */
AForm* Intern::createShrubberyCreationForm(std::string const& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string const& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string const& target)
{
    return new PresidentialPardonForm(target);
}

/* FORM CREATION ARRAY */
const Intern::FormType Intern::formTypes[3] = {
    {"shrubbery creation", &Intern::createShrubberyCreationForm},
    {"robotomy request", &Intern::createRobotomyRequestForm},
    {"presidential pardon", &Intern::createPresidentialPardonForm}
};

AForm* Intern::makeForm(std::string const& formName, std::string const& target)
{
    std::cout << GREEN << "\n[Form name: " << formName << "]" << std::endl << RESET;
    std::cout << "---------------------------------" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i].name)
        {
            std::cout << "Intern creates " << formName << " form" << std::endl;
            return formTypes[i].creator(target);
        }
    }
    std::cout << "Intern could not create " << formName << " form" << std::endl;
    return NULL;
}
