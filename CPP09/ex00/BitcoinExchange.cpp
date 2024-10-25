/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:31:23 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/25 13:41:42 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>  // ifstream
#include <iostream> // cerr, endl, exit, cout, 
#include <sstream>  // istringstream
#include <regex>    // regex_match, regex
#include <limits>   // numeric_limits

/* CONSTRUCTORS, DESTRUCTOR, OPERATOR= */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->db = other.db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/* PARSER */

// Check if the date has valid format YYYY-MM-DD
// Regex is used to check the format of the date string
// How to read regex: \d{4}-\d{2}-\d{2} means 
//     \d is a digit, {4} means 4 digits, - is a dash, \d{2} means 2 digits, and so on
// regrex_match means that the whole string must match the pattern
// It has two arguments: the string to match and the pattern
bool BitcoinExchange::isValidDate(const std::string& date) {
    std::regex datePattern(R"((\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]))");
    return std::regex_match(date, datePattern);
}

// Check if the value is valid (not negative and not too large)
bool BitcoinExchange::isValidValue(double value) const {
    return value >= 0 && value <= std::numeric_limits<int>::max();
}

bool BitcoinExchange::validateDate(const std::string& line) {
    // Extract the date from line
    std::istringstream iss(line);
    std::string date;
    iss >> date;
    if (!isValidDate(date)) {
        std::cerr << "Error: Bad input => " << date << std::endl;
            return false;
    }
    return true;
}

// Read the CSV file and store the data in the db map
void BitcoinExchange::readDb(const std::string& filename) {
    std::ifstream file(filename); // open file
    std::string line;
    std::string date;
    double value;
    std::smatch match;
    
    // linePattern means that the line must have a date in the format YYYY-MM-DD, a pipe, and a value
    std::regex linePattern(R"((\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]) \| (-?\d+(\.\d+)?))"); 
    
    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    
    // Skip the header line
    std::getline(file, line);

    // Read the file line by line
    while(std::getline(file, line)) {
        if (!validateDate(line)) {
            continue;
        }
        std::cout << "Line: " << line << std::endl;
        if (std::regex_match(line, match, linePattern)) {
            
            // Extract the date and value from the matched groups
            date = match[1].str();
            std::cout << "Date: " << match[1] << std::endl;
            std::cout << "Value: " << match[2]<< std::endl;
            std::cout << "match 3: " << match[3] << std::endl;
            std::cout << "match 4: " << match[4] << std::endl; 
            value = std::stod(match[4]);
            
            // Validate the value
            if (!isValidValue(value)) {
                if (value < 0) {
                    std::cerr << "Error: Not a positive numer. " << std::endl;
                } else {
                    std::cerr << "Error: Value too large. " << std::endl;
                }
            }

            // Inserts the parsed date and value into the map
            db[date] = value;
        } else {
            std::cerr << "Error: could not parse line " << line << std::endl;
        }
    }
    
/*     // Read the file line by line
    while(std::getline(file, line)) {
        std::istringstream iss(line); // init an input string stream with a line
        
        // Parse each line into a date and a value
        if (iss >> date >> pipe >> value && pipe == '|') {
            db[date] = value; // Inserts the parsed date and value into the map
            //std::cout << "Date: " << date << " Value: " << value << std::endl;        
        } else {
            std::cerr << "Error: could not parse line " << line << std::endl;
        }
        std::cout << "File " << filename << " read successfully line: " << line << std::endl;
    } */
    file.close();
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    auto it = db.lower_bound(date); // first element that is not less than date
    if (it == db.begin() || it->first != date) {
        if (it == db.begin()) {
            return "";
        }
        --it;
    }
    return it->first;
}


