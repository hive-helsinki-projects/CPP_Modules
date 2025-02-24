/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:02:44 by lkilpela          #+#    #+#             */
/*   Updated: 2025/02/24 18:26:50 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <iostream>

// Function to check if the date has valid format YYYY-MM-DD
bool isValidDate(const std::string& date) {
    std::regex datePattern(R"((\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]))");
    if (!std::regex_match(date, datePattern)) {
        return false;
    }

    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

    // Check for invalid days in each month
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2) { // Leap year check
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28)) return false;
    } else if (day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

// Function to check if the value is a valid exchange rate
bool isValidValue(const std::string& valueStr, double& value) {
    try {
        value = std::stod(valueStr);
        return value >= 0 && value <= 1000;
    } catch (...) {
        return false;
    }
}

// Function to validate the input line
void validateDate(const std::string& line) {
    std::istringstream iss(line);
    std::string date;
    iss >> date;
    if (!isValidDate(date)) {
        throw std::runtime_error("Error: bad input => " + date);
    }
}

// Function to parse exchange rate data from CSV
std::map<std::string, double> parseDataFile(const std::string& dataFile) {
    std::ifstream file(dataFile);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file");
    }

    std::map<std::string, double> rates;
    std::string line;
    
    if (!std::getline(file, line) || line != "date,exchange_rate") {
        throw std::runtime_error("Error: Invalid CSV format");
    }

    while (std::getline(file, line)) {
        size_t comma = line.find(',');
        if (comma == std::string::npos) {
            throw std::runtime_error("Error: Invalid data format in " + line);
        }

        std::string date = line.substr(0, comma);
        validateDate(date);
        double rate = std::stod(line.substr(comma + 1));

        rates[date] = rate;
    }
    return rates;
}