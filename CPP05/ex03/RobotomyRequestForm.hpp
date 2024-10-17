/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:56:17 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 21:38:08 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(RobotomyRequestForm const& other);
    RobotomyRequestForm& operator=(RobotomyRequestForm const& other);
    ~RobotomyRequestForm();

    void execute(const Bureaucrat& executor) const override;
};

#endif
