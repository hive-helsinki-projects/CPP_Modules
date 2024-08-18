/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:08:25 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/18 19:09:47 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

void HarlFilter::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void HarlFilter::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void HarlFilter::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void HarlFilter::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void HarlFilter::complain(std::string level) {
    std::map<std::string, void (HarlFilter::*)()> mymap;
    
    mymap["debug"] = &HarlFilter::debug;
    mymap["info"] = &HarlFilter::info;
    mymap["warning"] = &HarlFilter::warning;
    mymap["error"] = &HarlFilter::error;

    auto it = mymap.find(level);
    if(it != mymap.end()) 
        (this->*it->second)();
    else
        std::cout << "Invalid\n";
}