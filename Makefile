# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 14:55:29 by mabdessm          #+#    #+#              #
#    Updated: 2024/08/07 16:57:39 by mabdessm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra -Iincludes -fsanitize=address
MLXFLAGS = -lmlx -lXext -lX11
RM = rm -rf

SRCS = solong/so_long.c

OBJS = $(SRCS:.c=.o)

$(NAME):
	@echo "\033[0;31mcompiling ${NAME}...\033[0m"
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "\033[0;32m${NAME} compiled!\033[0m"
	@echo

all: $(NAME)

clean:
	@echo "\033[0;31mdeleting objects...\033[0m"
	$(RM) $(OBJS)
	@echo "\033[0;32mobjects deleted!\033[0m"
	@echo

fclean: clean
	@echo "\033[0;31mdeleting ${NAME} exe...\033[0m"
	$(RM) $(NAME)
	@echo "\033[0;32m${NAME} exe deleted!\033[0m"
	@echo

re: fclean all

.PHONY: all re clean fclean