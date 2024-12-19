/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:35:30 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/19 14:11:29 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <stack> // stack
#include <stdexcept> // runtime_error
#include <cctype> // isdigit
#include <cstdlib> // strtol
#include <sstream> // istringstream
#include <iostream> // cout

/* CONSTRUCTOR, DESTRUCTOR */
RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

bool isValidOperator(const std::string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool isValidToken(const std::string& token) {
    try {
        if(!isValidOperator(token)) {
            std::stoi(token);
        }
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}

/* MEMBER FUNCTION */
int RPN::evaluate(const std::string& expression) {
    std::cout << "Evaluating expression: " << expression << std::endl;

    if (expression.empty() || expression.size() < 3) {
        throw std::runtime_error("Error: invalid expression");
    }
    
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (!isValidToken(token)) {
            throw std::runtime_error("Error: invalid token in expression: " + token);
        }
        if (!isValidOperator(token)) {
            stack.push(std::stoi(token));
        } else {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: not enough numbers");
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            switch (token[0]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    if (b == 0) {
                        throw std::runtime_error("Error: division by zero");
                    }
                    stack.push(a / b);
                    break;
                default:
                    throw std::runtime_error("Error: invalid operator");
            }
        }
    }
    if (stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression");
    }

    return stack.top();
}