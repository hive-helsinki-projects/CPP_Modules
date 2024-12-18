/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:32:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/18 23:07:35 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream> // cerr, endl
#include <fstream>  // ifstream
#include <regex>    // regex_match, regex
#include "Utils.hpp"

void processInputFile(const std::string& inputFile, const BitcoinExchange& btc) {
   std::ifstream file(inputFile);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open input file");
    }

    std::string line;
    if (std::getline(file, line)) {
        if (line != "date | value") {
            std::cerr << "Warning: Invalid header format. Expected 'date | value', found '" << line << "'" << std::endl;
        }
    } else {
        std::cerr << "Warning: Input file is empty." << std::endl;
        return;
    }

    std::regex linePattern(R"((\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]) \| (-?\d+(\.\d+)?))");
    std::smatch match;
    bool hasValidLine = false;

    while (std::getline(file, line)) {
        try {
            validateDate(line);
            if (std::regex_match(line, match, linePattern)) {
                hasValidLine = true;
                std::string date = match[1].str() + "-" + match[2].str() + "-" + match[3].str();
                std::string valueStr = match[4].str();

                double value;
                if (!isValidValue(valueStr, value)) {
                    if (value < 0) {
                        throw std::runtime_error("Error: not a positive number.");
                    } else {
                        throw std::runtime_error("Error: too large a number.");
                    }
                }
                double rate = btc.getExchangeRate(date);
                std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
            } else {
                throw std::runtime_error("Error: Invalid line format => " + line);
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    if (!hasValidLine) {
        std::cerr << "Warning: No valid lines found in input file." << std::endl;
    }
} 

int main(int argc, char **argv) {
    try {
        if (argc != 2) {
            throw std::runtime_error("Error: could not open file");
        }
        std::map<std::string, double> exchangeRates = parseDataFile("data.csv");
        BitcoinExchange btc(exchangeRates);

        processInputFile(argv[1], btc);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
