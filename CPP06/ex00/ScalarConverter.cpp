/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:39:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/15 09:02:52 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream> // std::cout, std::cerr, std::endl
#include <iomanip> // std::fixed, std::setprecision
#include <exception> // std::invalid_argument
#include <limits>
#include <sstream>
#include <cmath>

bool ScalarConverter::isCharLiteral(const std::string& literal) {
    return literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return literal == "-inf" || literal == "+inf" || literal == "nan" ||
            literal == "-inff" || literal == "+inff" || literal == "nanf";
}

bool ScalarConverter::isInteger(const std::string& literal) {
    try {
        std::stoi(literal);
        return true;
    } catch (...) {
        return false;
    }
}

bool ScalarConverter::isFloat(const std::string& literal) {
    try {
        if (literal.back() == 'f') {
            std::stof(literal);
            return true;
        }
        return false;
    } catch (...) {
        return false;
    }
}

bool ScalarConverter::isDouble(const std::string& literal) {
    try {
        if (literal.find('.') != std::string::npos) {
            std::stod(literal);
            return true;
        }
        return false;
    } catch (...) {
        return false;
    }
}

void ScalarConverter::handlePseudoLiteral(const std::string& literal) {
    if (literal == "-inff" || literal == "-inf") {
        printChar(-INFINITY);
        printInt(static_cast<int>(-INFINITY));
        printFloat(-INFINITY);
        printDouble(-INFINITY);
    } else if (literal == "+inff" || literal == "+inf") {
        printChar(INFINITY);
        printInt(static_cast<int>(INFINITY));
        printFloat(INFINITY);
        printDouble(INFINITY);
    } else if (literal == "nanf" || literal == "nan") {
        printChar(NAN);
        printInt(0);
        printFloat(NAN);
        printDouble(NAN);
    }
}

void ScalarConverter::printChar(double value) {
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127) {
        std::cout << "char: impossible" << '\n';
    } else if (value < 32 || value == 127) {
        std::cout << "char: Non displayable" << '\n';
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'\n";
    }
}

void ScalarConverter::printInt(double value) {
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << '\n';
    } else {
        std::cout << "int: " << static_cast<int>(value) << '\n';
    }
}

void ScalarConverter::printFloat(float value) {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << value << "f\n";
}

void ScalarConverter::printDouble(double value) {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << value << '\n';
}

void ScalarConverter::convert(const std::string& literal) {
    try {
        if (isCharLiteral(literal)) {
            char c = literal[1];
            printChar(c);
            printInt(static_cast<int>(c));
            printFloat(static_cast<float>(c));
            printDouble(static_cast<double>(c));
        } else if (isPseudoLiteral(literal)) {
            handlePseudoLiteral(literal);
        } else if (isInteger(literal)) {
            int i = std::stoi(literal);
            printChar(i);
            printInt(i);
            printFloat(static_cast<float>(i));
            printDouble(static_cast<double>(i));
        } else if (isFloat(literal)) {
            float f = std::stof(literal);
            printChar(f);
            printInt(static_cast<int>(f));
            printFloat(f);
            printDouble(static_cast<double>(f));
        } else if (isDouble(literal)) {
            double d = std::stod(literal);
            printChar(d);
            printInt(static_cast<int>(d));
            printFloat(static_cast<float>(d));
            printDouble(d);
        } else {
            throw std::invalid_argument("Unknown literal format");
        }
    } catch (const std::exception& e) {
        std::cerr << "Conversion error: " << e.what() << '\n';
    }
}



/*
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

void convertChar(long double ld)
{
    if (ld >= 32 && ld <= 126) {
        std::cout << "char: '" << static_cast<char>(ld) << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    } 
}

void convertInt(long double ld)
{
    try {
        if (ld < std::numeric_limits<int>::min()
            || ld > std::numeric_limits<int>::max()) {
            throw std::out_of_range("int overflow/underflow");
        } else {
            std::cout << "int: " << static_cast<int>(ld) << std::endl;
        }
    } catch (const std::out_of_range&) {
        std::cout << "int: impossible" << std::endl;
    } 
    if (ld < std::numeric_limits<int>::min() || ld > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(ld) << std::endl;
    }
}

void convertFloat(long double ld)
{

     try {
        if (ld < std::numeric_limits<float>::lowest()
            || ld > std::numeric_limits<float>::max()) {
            throw std::out_of_range("float overflow/underflow");
        } else {
            float f = static_cast<float>(ld);
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << f << "f" << std::endl;
        }
    } catch (const std::out_of_range&) {
        std::cout << "float: impossible" << std::endl;
    } 
    if (ld < -std::numeric_limits<float>::max() || ld > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        float f = static_cast<float>(ld);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
    }
}

void convertDouble(long double ld)
{
     try {
        if (ld < std::numeric_limits<double>::lowest()
            || ld > std::numeric_limits<double>::max()) {
            throw std::out_of_range("double overflow/underflow");
        } else {
            double d = static_cast<double>(ld);
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "double: " << d << std::endl;
        }
    } catch (const std::out_of_range&) {
        std::cout << "double: impossible" << std::endl;
    }
    if (ld < -std::numeric_limits<double>::max() || ld > std::numeric_limits<double>::max()) {
        std::cout << "double: impossible" << std::endl;
    } else {
        double d = static_cast<double>(ld);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convert(const std::string &input)
{
    size_t pos = 0;
    long double ld = 0.0;

    if (isSpecialLiteral(input)) {
        specialLiteral(input);
        return;
    }
        // Handle regular int, char, float and double literals
    try {
        if (input.length() == 1 && !std::isdigit(input[0]))
            ld = static_cast<long double>(input[0]);
        else {
            // Convert to double first to handle both float and double literals
            ld = std::stold(input, &pos);
            if (pos != input.length() && input[pos] != 'f')
                throw std::invalid_argument("Invalid input");
        }
        
        // Convert to char
        convertChar(ld);
        
        // Convert to int
        convertInt(ld);

        // Convert to float
        convertFloat(ld);

        // Convert to double
        convertDouble(ld);
    } catch (const std::invalid_argument&) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
 */