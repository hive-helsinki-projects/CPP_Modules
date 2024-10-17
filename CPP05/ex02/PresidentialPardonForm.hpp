/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:37:34 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 10:38:29 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>
# include <cstdlib>

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(PresidentialPardonForm const& other);
    PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
    ~PresidentialPardonForm();

    void action() const;
};

#endif
