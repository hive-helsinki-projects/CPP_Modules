/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:36:53 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/14 22:20:06 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string> // std::string, std::stoi, std::stof, std::stod

class ScalarConverter {
private:
    ScalarConverter() {}
    ScalarConverter(ScalarConverter const&);
    ScalarConverter& operator=(ScalarConverter const&);  
    ~ScalarConverter() {}

    static void handlePseudoLiteral(const std::string& literal);
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(float value);
    static void printDouble(double value);
public:
    static bool isCharLiteral(const std::string& literal);
    static bool isPseudoLiteral(const std::string& literal);
    static bool isInteger(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    static void convert(const std::string& literal);

};

#endif