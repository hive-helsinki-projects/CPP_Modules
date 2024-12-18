#pragma once

#include <string>
#include <map>

bool isValidDate(const std::string& date);
bool isValidValue(const std::string& valueStr, double& value);
void processInputFile(const std::string& inputFile, const BitcoinExchange& btc);
void validateDate(const std::string& line);
std::map<std::string, double> parseDataFile(const std::string& dataFile);