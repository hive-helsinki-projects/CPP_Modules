/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:39:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/18 14:38:55 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isSpecialLiteral(const std::string &input) {
    return (input == "-inff" || input == "+inff" || input == "nanf" ||
            input == "-inf" || input == "+inf" || input == "nan");
}

void specialLiteral(std::string const& input)
{
    if (isSpecialLiteral(input))
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
    return ;
}

void charConvert(double d)
{
    if (d >= 32 && d <= 126) {
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    } 
}

void intConverter(double d)
{
    try {
        if (d < std::numeric_limits<int>::min()
            || d > std::numeric_limits<int>::max()) {
            throw std::out_of_range("int overflow/underflow");
        } else {
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        }
    } catch (const std::out_of_range&) {
        std::cout << "int: impossible" << std::endl;
    }
}

void floatConverter(double d)
{
    try {
        std::cout << d << std::endl;
        if (d < std::numeric_limits<float>::lowest()
            || d > std::numeric_limits<float>::max()) {
            throw std::out_of_range("float overflow/underflow");
        } else {
            float f = static_cast<float>(d);
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << f << "f" << std::endl;
        }
    } catch (const std::out_of_range&) {
        std::cout << "float: impossible" << std::endl;
    }
}

void doubleConverter(double d)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &input)
{
    size_t pos = 0;
    double d = 0.0;

    // Handle special float and double literals
    specialLiteral(input);

    // Handle regular int, char, float and double literals
    try {
        // Convert to double first to handle both float and double literals
        d = std::stod(input, &pos);
        if (pos != input.length() && input[pos] != 'f')
            throw std::invalid_argument("Invalid input");

        // Convert to char
        charConvert(d);
        
        // Convert to int
        intConverter(d);

        // Convert to float
        floatConverter(d);

        // Convert to double
        doubleConverter(d);
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
