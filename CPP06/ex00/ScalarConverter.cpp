/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:39:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/18 23:13:37 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream> // std::cout, std::cerr, std::endl
#include <iomanip> // std::fixed, std::setprecision
#include <exception> // std::invalid_argument
#include <limits>
#include <sstream>
#include <cmath>
#include <regex>

static bool IsCharLiteral(const std::string& input)
{
    return input.length() == 3 && input[0] == '\'' && input[2] == '\'';
}

/*This regular expression will match:

Optional leading minus sign (-?)
One or more digits before the decimal point (\d+)
Decimal point (\.)
One or more digits after the decimal point (\d+)
Optional trailing 'f' for float literals (f?)*/
bool isDecimal(const std::string& input ) {
/*     auto p = input.find('.');
    if (p == std::string::npos && p  < 1 && p >= input.size() - 2)
        return false;
    return std::isdigit(input[p - 1]) || std::isdigit(input[p + 1]); */
    static const std::regex decimalRegex(R"(^-?\d+\.\d+(f)?$)");
    return std::regex_match(input, decimalRegex);
}

bool isInteger(const std::string& input) {
    // Regex for valid integers:
    // - Optional leading minus sign
    // - At least one digit
    std::regex integerRegex(R"(^-?\d+$)");
    return std::regex_match(input, integerRegex);
}

bool isValidInput(const std::string& input) {

    if (IsCharLiteral(input)) return true;
    std::regex specialFloats(R"(^[-+]?(inf|nan)f?$)", std::regex::icase);
    if (std::regex_match(input, specialFloats)) return true;
    try {
/*         if (IsCharLiteral(input)) {
            return true;
        } */
        size_t pos = 0;
        std::stod(input, &pos);
        return pos == input.size() /* || (isDecimal(input) && input.substr(pos) == "f") */;
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
        if (IsCharLiteral(input))
            v = static_cast<int>(input[1]);
        else {
            size_t pos = 0;
            v = std::stoi(input, &pos);
            if (pos != input.size()) {
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
        if (IsCharLiteral(input))
            v = static_cast<float>(input[1]);
        else if (isDecimal(input) || isInteger(input)) {
            v = std::stof(input);
        } else {
            throw std::invalid_argument("Invalid float format");
        }
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
        else if (isDecimal(input) || isInteger(input)) {
            v = std::stod(input);
        } else {
            throw std::invalid_argument("Invalid double format");
        }
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
