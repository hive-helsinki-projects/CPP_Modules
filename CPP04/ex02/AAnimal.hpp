/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:19:02 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/14 16:13:07 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

#define GREEN "\033[0;32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESET "\033[0m"

class AAnimal {
protected:
    std::string type;    

public:
    AAnimal();
    AAnimal(const std::string& type);
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    virtual void makeSound() const = 0; // Pure virtual function

    std::string getType() const; 
};

#endif
