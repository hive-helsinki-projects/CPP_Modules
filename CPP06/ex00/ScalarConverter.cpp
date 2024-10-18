/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:39:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/18 11:49:30 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isSpecialLiteral(const std::string &input) {
    return (input == "-inff" || input == "+inff" || input == "nanf" ||
            input == "-inf" || input == "+inf" || input == "nan");
}

void ScalarConverter::convert(const std::string &input) {
    // Handle special float and double literals
    if (isSpecialLiteral(input)) {
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
        return;
    }

    size_t pos = 0;
    double d = 0.0;

    try {
        // Convert to double first to handle both float and double literals
        d = std::stod(input, &pos);
        if (pos != input.length() && input[pos] != 'f')
            throw std::invalid_argument("Invalid input");

        // Convert to char
        if (d >= 32 && d <= 126) {
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }

        // Convert to int
        if (d >= std::numeric_limits<int>::min()
            && d <= std::numeric_limits<int>::max()) {
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        } else {
            std::cout << "int: impossible" << std::endl;
        }

        // Convert to float
        if (d >= -std::numeric_limits<float>::max()
            && d <= std::numeric_limits<float>::max()) {
            float f = static_cast<float>(d);
            if (f == std::numeric_limits<float>::infinity() 
                || f == -std::numeric_limits<float>::infinity()) {
                std::cout << "float: impossible" << std::endl;
            } else {
                std::cout << std::fixed << std::setprecision(1);
                std::cout << "float: " << f << "f" << std::endl;
            }
        } else {
            std::cout << "float: impossible" << std::endl;
        }

        // Convert to double
        if (d == std::numeric_limits<double>::infinity()
            || d == -std::numeric_limits<double>::infinity()) {
            std::cout << "double: impossible" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "double: " << d << std::endl;
        }
    } catch (const std::out_of_range&) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    } catch (const std::invalid_argument&) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
