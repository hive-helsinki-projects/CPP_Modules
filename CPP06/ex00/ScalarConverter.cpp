#include "ScalarConverter.hpp"
#include <iostream> // std::cout, std::endl
#include <string> // std::string
#include <limits> // std::numeric_limits
#include <cstdlib> // std::out_of_range
#include <cctype> // std::isprint
#include <cmath> // std::isinf, std::isnan
#include <iomanip> // std::fixed, std::setprecision
#include <regex> // std::regex, std::regex_match

enum LiteralType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,
    UNKNOWN
};

static LiteralType detectLiteralType(const std::string& input) {
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
        return CHAR;
    else if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
        return SPECIAL;
    // Regular expressions for valid FLOAT and DOUBLE types
    std::regex floatPattern(R"(^-?\d+\.\d+f$)");
    std::regex doublePattern(R"(^-?\d+\.\d+$)");

    if (std::regex_match(input, floatPattern)) {
        return FLOAT;
    } else if (std::regex_match(input, doublePattern)) {
        return DOUBLE;
    }

    // Regular expression for valid INT type
    std::regex intPattern(R"(^-?\d+$)");
    if (std::regex_match(input, intPattern)) {
        return INT;
    }

    return UNKNOWN;
}

template <typename T>
bool convertTo(const std::string& literal, T& result) {
    try {
        if (std::is_same_v<T, int>) {
            long long value = std::stoll(literal);
            if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
                return false; // overflow
            }
            result = static_cast<int>(value);
        } else if (std::is_same_v<T, float>) {
            result = std::stof(literal);
        } else if (std::is_same_v<T, double>) {
            result = std::stod(literal);
        }
        return true; // No overflow
    } catch (const std::out_of_range&) {
        return false; // overflow
    } catch (const std::exception&) {
        throw;
    }
}

static void printResults(char c, int i, float f, double d, bool special = false, bool overflow = false, bool foverflow = false, bool doverflow = false) {
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

    if (foverflow)
        std::cout << "float: impossible" << std::endl;
    else if (std::isinf(f) || std::isnan(f))
        std::cout << "float: " << f << "f" << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
    }

    if (doverflow)
        std::cout << "double: impossible" << std::endl;
    else if (std::isinf(d) || std::isnan(d))
        std::cout << "double: " << d << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    try {
        LiteralType type = detectLiteralType(literal);
        bool overflow = false;
        bool foverflow = false;
        bool doverflow = false;
        switch (type) {
            case CHAR: {
                char c = literal[1];
                printResults(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
                break;
            }
            case INT: {
                int i;
                if (!convertTo<int>(literal, i)) {
                    overflow = true;
                }
                float f;
                convertTo<float>(literal, f);
                double d;
                convertTo<double>(literal, d);
                printResults(static_cast<char>(i), i, f, d, false, overflow, foverflow);
                break;
            }
            case FLOAT: {
                float f;
                if (!convertTo<float>(literal, f)) {
                    foverflow = true;
                    overflow = true;
                }
                double d;
                convertTo<double>(literal, d);
                printResults(static_cast<char>(f), static_cast<int>(f), f, d, false, overflow, foverflow);
                break;
            }
            case DOUBLE: {
                double d;
                if (!convertTo<double>(literal, d)) {
                    throw std::out_of_range("Double overflow");
                }
                printResults(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d, false, overflow, foverflow, doverflow);
                break;
            }
            case SPECIAL: {
                float f;
                convertTo<float>(literal, f);
                double d;
                convertTo<double>(literal, d);
                printResults('?', '?', f, d, true);
                break;
            }
            default:
                throw std::invalid_argument("Unknown literal type");
        }
    } catch (...) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    }
}