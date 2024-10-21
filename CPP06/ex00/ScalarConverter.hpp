/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:36:53 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/21 15:32:16 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string> // std::string, std::stoi, std::stof, std::stod

class ScalarConverter {
private:
    ScalarConverter() {};  
    ~ScalarConverter() {};
public:
    static void convert(std::string const& input);
};

#endif