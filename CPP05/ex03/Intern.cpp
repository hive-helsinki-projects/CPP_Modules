/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:12:34 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 15:33:57 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const& other)
{
    *this = other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(Intern const& other)
{
    (void)other;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

/* FORM CREATION FUNCTIONS */
AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

/* FORM CREATION ARRAY */
const Intern::FormType Intern::formTypes[3] = {
    {"shrubbery creation", &Intern::createShrubberyCreationForm},
    {"robotomy request", &Intern::createRobotomyRequestForm},
    {"presidential pardon", &Intern::createPresidentialPardonForm}
};

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
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
