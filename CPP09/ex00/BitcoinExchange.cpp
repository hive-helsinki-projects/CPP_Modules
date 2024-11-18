/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:26:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/18 15:32:49 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* CONSTRUCTORS, DESTRUCTOR, OPERATOR= */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->exchangeRates = other.exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dataFile) {
    std::ifstream file(dataFile);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    // Skip the header line
    std::getline(file, line);
    
    std::string date;
    double rate;
    size_t comma;
    while (std::getline(file, line)) {
        comma = line.find(',');
        if (comma == std::string::npos) {
            throw std::runtime_error("Invalid data format");
        }
        // Extract date and rate from line
        date = line.substr(0, comma);
        rate = std::stod(line.substr(comma + 1));

        exchangeRates[date] = rate;
    }
    file.close();
}

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
