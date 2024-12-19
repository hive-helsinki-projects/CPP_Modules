# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 10:48:55 by lkilpela          #+#    #+#              #
#    Updated: 2024/12/19 13:31:12 by lkilpela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	RPN

CC			=	c++
CCFLAGS		=	-Wall -Wextra -Werror -std=c++11
SRCS		=	main.cpp RPN.cpp
OBJS		=	$(SRCS:%.cpp=%.o)

all: $(NAME)

%.o : %.cpp
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $< $(RESET)"

$(NAME): $(OBJS)
	@echo "--------------------------------------------"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "[$(NAME)] $(BLUE)Built target $(NAME)$(RESET)"
	@echo "--------------------------------------------"

test: $(NAME)
	@echo "$(BLUE)Running tests... $(RESET)"
	@echo "Test 1 $(GREEN)Expected result: 42 $(RESET)"
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "--------------------------------------------"
	@echo "Test 2 $(GREEN)Expected result: 42 $(RESET)"
	@./$(NAME) "7 7 * 7 -"
	@echo "--------------------------------------------"
	@echo "Test 3 $(GREEN)Expected result: 0 $(RESET)"
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@echo "--------------------------------------------"
	@echo "Test 4 $(GREEN)Expected result: Error $(RESET)"
	-@./$(NAME) "(1 + 1)"
	@echo "--------------------------------------------"
	@echo "Test 5 $(GREEN)Expected result: Error $(RESET)"
	-@./$(NAME) ""
	@echo "--------------------------------------------"
	@echo "Test 6 $(GREEN)Expected result: Error $(RESET)"
	-@./$(NAME) "1 2 3 4 5 6 7 8 9 10"
	@echo "--------------------------------------------"
	@echo "Test 7 $(GREEN)Expected result: Error $(RESET)"
	-@./$(NAME) "6"
	@echo "--------------------------------------------"
	@echo "Test 8 $(GREEN)Expected result: Error $(RESET)"
	-@./$(NAME) "5 +"
	@echo "--------------------------------------------"
	@echo "Test 9 $(GREEN)Expected result: Error $(RESET)"
	-@./$(NAME) "+"
	@echo "--------------------------------------------"
	@echo "Test 10 $(GREEN)Expected result: Error $(RESET)"
	-@./$(NAME) "4 0 /"
	@echo "--------------------------------------------"
	@echo "Test 11 $(GREEN)Expected result: Error $(RESET)"
	-@./$(NAME) "3 4 5 +"
	@echo "--------------------------------------------"
	@echo "Test 12 $(GREEN)Expected result: 7 $(RESET)"
	-@./$(NAME) "3 4 +"
	@echo "--------------------------------------------"
	@echo "Test 13 $(GREEN)Expected result: Error $(RESET)"
	-@./$(NAME) "3 4"
	@echo "--------------------------------------------"
	@echo "Test 14 $(GREEN)Expected result: Error $(RESET)"
	-@./$(NAME) "3 4 + 50"
	@echo "--------------------------------------------"

clean:
	@rm -rf $(OBJS)
	@echo "[$(NAME)] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[$(NAME)] Everything deleted."

re: fclean all
	@echo "[$(NAME)] Everything rebuilt."

.PHONY: all clean fclean re

GREEN = \033[0;32m
RESET = \033[0m
BLUE = \033[34m