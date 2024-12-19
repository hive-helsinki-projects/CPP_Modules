/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:26:53 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/19 08:31:13 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map> // std::map
#include <string> // std::string

class BitcoinExchange {
private:
    std::map<std::string, double> exchangeRates; // Store exchange rates in container

public:
    BitcoinExchange();
    explicit BitcoinExchange(const std::map<std::string, double>& rates);   
    //BitcoinExchange(const std::string& dataFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange &operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    double getExchangeRate(const std::string& date) const;
};
