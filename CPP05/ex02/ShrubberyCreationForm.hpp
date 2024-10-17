/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:43:24 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 22:30:25 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm {
private:
    std::string target;
public:
    ShrubberyCreationForm() = delete;
    ShrubberyCreationForm(std::string const& target);
    ShrubberyCreationForm(ShrubberyCreationForm const& other) = delete;
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other) = delete;
    ~ShrubberyCreationForm();

    std::string getTarget() const;
    void execute(Bureaucrat const& executor) const;
};

#endif
