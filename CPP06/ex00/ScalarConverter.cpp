#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iomanip>

enum LiteralType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,
    UNKNOWN
};

static LiteralType detectLiteralType(const std::string& input) {
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        return CHAR;
    } else if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff") {
        return SPECIAL;
    } else if (input.find('.') != std::string::npos) {
        if (input.back() == 'f') {
            return FLOAT;
        } else {
            return DOUBLE;
        }
    } else {
        return INT;
    }
}

template <typename T>
T convertTo(const std::string& literal) {
    try {
        if constexpr (std::is_same_v<T, int>) {
            return std::stoi(literal);
        } else if constexpr (std::is_same_v<T, float>) {
            return std::stof(literal);
        } else if constexpr (std::is_same_v<T, double>) {
            return std::stod(literal);
        }
    } catch (const std::exception&) {
        return std::numeric_limits<T>::infinity();
    }
}

static void printResults(char c, int i, float f, double d) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (i == std::numeric_limits<int>::infinity())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (std::isinf(f) || std::isnan(f))
        std::cout << "float: " << f << "f" << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
    }

    if (std::isinf(d) || std::isnan(d))
        std::cout << "double: " << d << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    try {
        LiteralType type = detectLiteralType(literal);
        switch (type) {
            case CHAR: {
                char c = literal[1];
                printResults(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
                break;
            }
            case INT: {
                int i = convertTo<int>(literal);
                float f = convertTo<float>(literal);
                double d = convertTo<double>(literal);
                printResults(static_cast<char>(i), i, f, d);
                break;
            }
            case FLOAT: {
                float f = convertTo<float>(literal);
                double d = convertTo<double>(literal);
                printResults(static_cast<char>(f), static_cast<int>(f), f, d);
                break;
            }
            case DOUBLE: {
                double d = convertTo<double>(literal);
                float f = convertTo<float>(literal);
                printResults(static_cast<char>(d), static_cast<int>(d), f, d);
                break;
            }
            case SPECIAL: {
                float f = convertTo<float>(literal);
                double d = convertTo<double>(literal);
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                printResults('?', '?', f, d);
                break;
            }
            default:
                throw std::invalid_argument("Unknown literal type");
        }
    } catch (const std::exception& e) {
        std::cerr << "Conversion error: " << e.what() << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}