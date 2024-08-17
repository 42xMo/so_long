# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 14:55:29 by mabdessm          #+#    #+#              #
#    Updated: 2024/08/17 02:01:44 by mabdessm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra -Iincludes #-fsanitize=address
MLXFLAGS = -L./minilibx-linux -lmlx -lXext -lX11
RM = rm -rf

SRCS = getnextline/get_next_line.c getnextline/get_next_line_utils.c \
		printf/ft_printf.c printf/ft_putchar.c printf/ft_putnbr_base.c \
		printf/ft_putnbr_base_p.c printf/ft_putnbr.c printf/ft_putstr.c \
		printf/ft_putunsigned.c solong/so_long.c solong/ft_split.c \
		solong/ft_calloc.c solong/ft_flood_fill.c

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