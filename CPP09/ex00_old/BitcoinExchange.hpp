/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:45:22 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/25 13:23:37 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange {
private:
    std::map<std::string, double> db; // database

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange &operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    //const std::map<std::string, double>& getDb() const;
    void readDb(const std::string& filename);
    std::string findClosestDate(const std::string& date) const;
    bool isValidDate(const std::string& date);
    bool validateDate(const std::string& line);  
    bool isValidValue(double value) const;
};
#endif