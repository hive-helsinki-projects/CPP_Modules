/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:43:24 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 21:38:15 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(ShrubberyCreationForm const& other);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
    ~ShrubberyCreationForm();

    std::string getTarget() const;
    void execute(const Bureaucrat& executor) const override;
};

#endif
