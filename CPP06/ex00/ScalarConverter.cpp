/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:39:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/18 15:53:27 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream> // std::cout, std::cerr, std::endl
#include <iomanip> // std::fixed, std::setprecision
#include <exception> // std::invalid_argument
#include <limits>
#include <sstream>
#include <cmath>

static bool IsCharLiteral(const std::string& input)
{
    return input.length() == 3 && input[0] == '\'' && input[2] == '\'';
}

bool isDecimal(const std::string& input ) {
    auto p = input.find('.');
    if (p < 1 || p > input.size() - 2)
        return false;
    return std::isdigit(input[p - 1]) && std::isdigit(input[p + 1]);
}

bool isValidInput(const std::string& input) {
    try {
        if (IsCharLiteral(input)) {
            return true;
        }
        size_t pos = 0;
        std::stod(input, &pos);
        return pos == input.size() || (isDecimal(input) && input.substr(pos) == "f");
    } catch (...) {
        return false;
    }
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
        else {
            size_t pos = 0;
            v = std::stoi(input, &pos);
            if(pos != input.size()) {
                double dv = std::stod(input);
                if (dv > std::numeric_limits<int>::max() || dv < std::numeric_limits<int>::min())
                    throw std::out_of_range("Out of range");
                v = static_cast<int>(dv);
            }                
        }
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
    if (isValidInput(input)) {
        // Convert to char
        convertChar(input);
        
        // Convert to int
        convertInt(input);

        // Convert to float
        convertFloat(input);

        // Convert to double
        convertDouble(input); 
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
