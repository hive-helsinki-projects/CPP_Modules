/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:35:46 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/24 15:57:49 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iterator>

template <typename T>
class MutanStack : public std::stack<T> {
public:
    // Type definitions for iterators
    using iterator = typename std::deque<T>::iterator;
    using const_iterator = typename std::deque<T>::const_iterator;

    using std::stack<T>::stack;
    using iterator = typename std::stack<T>::container_type::iterator;
    
    MutanStack() : std::stack<T>() {}
    MutanStack(const MutanStack& other) : std::stack<T>(other) {}
    MutanStack &operator=(const MutanStack& other) {
        std::stack<T>::operator=(other);
        return *this;
    }
    ~MutanStack() {}
  
    // Iterator methods
    iterator begin() {
        return std::stack<T>::c.begin();
    }
    iterator end() {
        return std::stack<T>::c.end();
    }
    const_iterator begin() const {
        return std::stack<T>::c.begin();
    }
    const_iterator end() const {
        return std::stack<T>::c.end();
    }
};

#endif