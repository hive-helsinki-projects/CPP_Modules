/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:39:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/15 13:54:40 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream> // std::cout, std::cerr, std::endl
#include <iomanip> // std::fixed, std::setprecision
#include <exception> // std::invalid_argument
#include <limits>
#include <sstream>
#include <cmath>

bool isSpecialLiteral(const std::string &input) {
    return (input == "-inff" || input == "+inff" || input == "nanf" ||
            input == "-inf" || input == "+inf" || input == "nan");
}

void specialLiteral(std::string const& input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (input == "+inf" || input == "-inf" || input == "nan") {
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
    } else if (input == "+inff" || input == "-inff" || input == "nanf") {
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
    } else {
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
    }
}
static bool IsCharLiteral(const std::string& input)
{
    return input.length() == 3 && input[0] == '\'' && input[2] == '\'';
}


void convertChar(const std::string& input)
{
    try {
        int v = 0;
        if(IsCharLiteral(input))
            v = static_cast<int>(input[1]);
        else
            v = std::stoi(input);
        if (std::isprint(v))
            std::cout << "char: '" << static_cast<char>(v) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl; 
    } catch (const std::out_of_range&) {
        std::cout << "char: impossible" << std::endl;
    } catch (const std::invalid_argument&) {
        std::cout << "char: impossible" << std::endl;
    }
}

void convertInt(const std::string& input)
{
    try {
        int v = 0;
        if(IsCharLiteral(input))
            v = static_cast<int>(input[1]);
        else
            v = std::stoi(input);
        std::cout << "int: " << v << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "int: impossible" << std::endl;
    } catch (const std::invalid_argument&) {
        std::cout << "int: impossible" << std::endl;
    }
}

void convertFloat(const std::string& input)
{
    try {
        float v = 0;
        if(IsCharLiteral(input))
            v = static_cast<float>(input[1]);
        else
            v = std::stof(input);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << v << "f" << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "float: impossible" << std::endl;
    } catch (const std::invalid_argument&) {
        std::cout << "float: impossible" << std::endl;
    }
}

void convertDouble(const std::string& input)
{
    try {
        double v = 0;
        if(IsCharLiteral(input))
            v = static_cast<double>(input[1]);
        else
            v = std::stod(input);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << v << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "double: impossible" << std::endl;
    } catch (const std::invalid_argument&) {
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::convert(const std::string &input)
{
    // Convert to char
    convertChar(input);
    
    // Convert to int
    convertInt(input);

    // Convert to float
    convertFloat(input);

    // Convert to double
    convertDouble(input); 
}
