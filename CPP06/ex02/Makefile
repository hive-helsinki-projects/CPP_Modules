# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 10:48:55 by lkilpela          #+#    #+#              #
#    Updated: 2024/10/23 11:41:01 by lkilpela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out

CC			=	c++
CCFLAGS		=	-Wall -Wextra -Werror -std=c++11
SRCS		=	main.cpp Base.cpp 
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

clean:
	@rm -rf $(OBJS)
	@echo "[$(NAME)] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[$(NAME)] Everything deleted."

re: fclean all
	@echo "[$(NAME)] Everything rebuilt."

test: $(NAME)
	@echo "$(BLUE)Running tests... $(RESET)"
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: 2147483648 (INT_MAX overflow) $(RESET)"
	@./$(NAME) 2147483648
	@echo "$(GREEN)Test: -2147483649 (INT_MIN underflow)$(RESET)"
	@./$(NAME) -2147483649
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: 4.9e38 (FLT_MAX 3.4e+38 overflow)$(RESET)"
	@./$(NAME) 4.9e38
	@echo "$(GREEN)Test: -4.9e38 (FLT_MAX -3.4e+38 underflow)$(RESET)"
	@./$(NAME) -4.9e38
	@echo "$(GREEN)Test: 2.2e-38 (FLT_MIN 1.17e-38 underflow)$(RESET)"
	@./$(NAME) 2.2e-38
	@echo "$(GREEN)Test: -2.2e-38 (FLT_MIN -1.17e-38 underflow)$(RESET)"
	@./$(NAME) -2.2e-38
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: 1e308 (DBL_MAX 1.79e+308 overflow)$(RESET)"
	@./$(NAME) 1e308
	@echo "$(GREEN)Test: -1e308 (DBL_MAX -1.79e+308 underflow)$(RESET)"
	@./$(NAME) -1e308
	@echo "$(GREEN)Test: 2e-308 (DBL_MIN 2.22e-308 underflow)$(RESET)"
	@./$(NAME) 2e-308
	@echo "$(GREEN)Test: -2e-308 (DBL_MIN -2.22e-308 underflow)$(RESET)"
	@./$(NAME) -2e-308
	@echo "--------------------------------------------"

.PHONY: all clean fclean re test

GREEN = \033[0;32m
RESET = \033[0m
BLUE = \033[34m