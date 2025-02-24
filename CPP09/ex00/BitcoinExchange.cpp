/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:26:49 by lkilpela          #+#    #+#             */
/*   Updated: 2025/02/24 18:28:50 by lkilpela         ###   ########.fr       */
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

BitcoinExchange::BitcoinExchange(const std::map<std::string, double>& rates)
: exchangeRates(rates) {}

/* METHODS */

// Function provides the correct exchange rate for the given date 
// or the closest previous date if an exact match is not found
double BitcoinExchange::getExchangeRate(const std::string& date) const {
    if (exchangeRates.empty()) {
        throw std::runtime_error("Error: No exchange rates available");
    }
    auto it = exchangeRates.lower_bound(date);

    if (it == exchangeRates.begin() && it->first != date) {
        throw std::runtime_error("Error: Date not found");
    }

    if (it == exchangeRates.end() || it->first != date) {
        --it;
    }
    return it->second;
}
