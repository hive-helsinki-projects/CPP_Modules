/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:08:25 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/18 19:27:17 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

void HarlFilter::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void HarlFilter::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void HarlFilter::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void HarlFilter::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void HarlFilter::complain(std::string level) {
    std::map<std::string, void (HarlFilter::*)()> mymap;
    
    mymap["DEBUG"] = &HarlFilter::debug;
    mymap["INFO"] = &HarlFilter::info;
    mymap["WARNING"] = &HarlFilter::warning;
    mymap["ERROR"] = &HarlFilter::error;

    auto it = mymap.find(level);
    if(it != mymap.end())
        (this->*it->second)();
    else
        std::cout << "Invalid\n";
}

void HarlFilter::filter(std::string level) {
    std::map<std::string, int> mymap;
    
    mymap["DEBUG"] = 1;
    mymap["INFO"] = 2;
    mymap["WARNING"] = 3;
    mymap["ERROR"] = 4;

    auto it = mymap.find(level);
    if (it != mymap.end()) {
        switch (it->second) {
            case 1:
                debug();
                [[fallthrough]];
            case 2:
                info();
                [[fallthrough]];
            case 3:
                warning();
                [[fallthrough]];
            case 4:
                error();
                break;
        }
    }
    else
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; 
}
