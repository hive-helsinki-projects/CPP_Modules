/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:32:55 by lkilpela          #+#    #+#             */
/*   Updated: 2025/02/24 18:32:45 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream> // cerr, endl
#include <fstream>  // ifstream
#include <regex>    // regex_match, regex
#include "Utils.hpp"

// Function to read and process input file containing Bitcoin exchange data
void processInputFile(const std::string& inputFile, const BitcoinExchange& btc) {
   std::ifstream file(inputFile);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open input file");
    }

    std::string line;
    if (!std::getline(file, line) || line != "date | value") {
        std::cerr << "Warning: Invalid header format" << std::endl;
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
        
        BitcoinExchange btc(parseDataFile("data.csv"));
        processInputFile(argv[1], btc);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
