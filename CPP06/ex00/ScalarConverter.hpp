/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:36:53 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/21 15:28:26 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream> // std::cout, std::cerr, std::endl
#include <string> // std::string, std::stoi, std::stof, std::stod
#include <iomanip> // std::fixed, std::setprecision
#include <cmath> // std::isnan, std::isinf, std::isfinite
#include <exception> // std::invalid_argument

class ScalarConverter {
private:
    ScalarConverter() {};  
    ~ScalarConverter() {};
public:
    static void convert(std::string const& input);
};

#endif