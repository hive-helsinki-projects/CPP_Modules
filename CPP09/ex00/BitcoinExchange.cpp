/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:26:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/18 22:20:17 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept> // std::runtime_error
#include <regex>    // regex_match, regex
#include <fstream>  // ifstream
#include <sstream>  // istringstream

/* CONSTRUCTORS, DESTRUCTOR, OPERATOR= */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::map<std::string, double>& exchangerates)
: exchangeRates(exchangerates) {}

/* METHODS */
double BitcoinExchange::getExchangeRate(const std::string& date) const {
    // find the element with the key that is not less than specific date
    auto it = exchangeRates.lower_bound(date);
    // check if the it points to first element and the key is not equal to date
    if (it == exchangeRates.begin() && it->first != date) {
        throw std::runtime_error("Date not found");
    }
    // check if it points to the end of the container or the key is not equal to date
    // decrement it to get the element is lower than requested date
    if (it == exchangeRates.end() || it->first != date) {
        --it;
    }
    return it->second;
}

/* UTILS */

// Check if the date has valid format YYYY-MM-DD
bool isValidDate(const std::string& date) {
    std::regex datePattern(R"((\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]))");
    return std::regex_match(date, datePattern);
}

bool isValidValue(const std::string& valueStr, double& value) {
    try {
        value = std::stod(valueStr);
        return value >= 0 && value <= 1000;
    } catch (...) {
        return false;
    }
}

void validateDate(const std::string& line) {
    // Extract the date from line
    std::istringstream iss(line);
    std::string date;
    iss >> date;
    if (!isValidDate(date)) {
        throw std::runtime_error("Error: bad input => " + date);
    }
}

std::map<std::string, double> parseDataFile(const std::string& dataFile) {
    std::ifstream file(dataFile);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file");
    }

    std::map<std::string, double> rates;
    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        size_t comma = line.find(',');
        if (comma == std::string::npos) {
            throw std::runtime_error("Error: Invalid data format in " + line);
        }

        std::string date = line.substr(0, comma);
        double rate = std::stod(line.substr(comma + 1));
        rates[date] = rate;
    }
    return rates;
}