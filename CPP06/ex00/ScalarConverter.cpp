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
        if (std::is_same_v<T, int>) {
            long long value = std::stoll(literal);
            if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
                throw std::out_of_range("int overflow/underflow");
            }
            return static_cast<int>(value);
        } else if (std::is_same_v<T, float>) {
/*          float value = std::stof(literal);
            if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) {
                throw std::out_of_range("float overflow/underflow");
            }
            return value; */
            return std::stof(literal);
        } else if (std::is_same_v<T, double>) {
/*             double value = std::stod(literal);
            if (value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max()) {
                throw std::out_of_range("double overflow/underflow");
            }
            return value; */
            return std::stod(literal);
        }
    } catch (const std::out_of_range&) {
        throw;
    } catch (const std::exception&) {
        throw;
    }
}

static void printResults(char c, int i, float f, double d, bool special = false, bool overflow = false) {
    if (!special) {
        if (!overflow) {
            if (std::isprint(c))
                std::cout << "char: '" << c << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }

        if (overflow) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << i << std::endl;
        }
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }

    if (std::isinf(f) || std::isnan(f))
        std::cout << "float: " << f << "f" << std::endl;
    else if (f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::lowest()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
    }

    if (std::isinf(d) || std::isnan(d))
        std::cout << "double: " << d << std::endl;
    else if (d > std::numeric_limits<double>::infinity() || d < std::numeric_limits<float>::lowest()) {
        std::cout << "double: impossible" << std::endl;
    }
    else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    try {
        LiteralType type = detectLiteralType(literal);
        bool overflow = false;
        switch (type) {
            case CHAR: {
                char c = literal[1];
                printResults(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
                break;
            }
            case INT: {
                int i;
                try {
                    i = convertTo<int>(literal);
                } catch (const std::out_of_range&) {
                    overflow = true;
                }
                float f = convertTo<float>(literal);
                double d = convertTo<double>(literal);
                printResults(static_cast<char>(i), i, f, d, false, overflow);
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
                printResults('?', '?', f, d, true);
                break;
            }
            default:
                throw std::invalid_argument("Unknown literal type");
        }
    } catch (const std::exception& e) {

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}