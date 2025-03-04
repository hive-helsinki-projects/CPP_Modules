/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:56:17 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 22:29:15 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm {
private:
    std::string target;
public:
    RobotomyRequestForm() = delete;
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(RobotomyRequestForm const& other) = delete;
    RobotomyRequestForm& operator=(RobotomyRequestForm const& other) = delete;
    ~RobotomyRequestForm();

    void execute(const Bureaucrat& executor) const override;
};

#endif
