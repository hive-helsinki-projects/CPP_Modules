/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:26:53 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/18 14:40:09 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map> // std::map
#include <string> // std::string
#include <fstream> // std::ifstream
#include <stdexcept> // std::runtime_error

class BitcoinExchange {
private:
    std::map<std::string, double> exchangeRates; // Store exchange rates in container

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& dataFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange &operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    double getExchangeRate(const std::string& date) const;
};
