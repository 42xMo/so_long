# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 14:55:29 by mabdessm          #+#    #+#              #
#    Updated: 2024/09/04 19:35:23 by mabdessm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
CC = cc
FLAGS = -Wall -Werror -Wextra #-fsanitize=address
MLXFLAGS = -L./minilibx-linux -lmlx -lbsd -lXext -lX11 -lm
INCLUDES = -I./includes -I./minilibx-linux

SRCS = getnextline/get_next_line.c getnextline/get_next_line_utils.c \
		printf/ft_printf.c printf/ft_putchar.c printf/ft_putnbr_base.c \
		printf/ft_putnbr_base_p.c printf/ft_putnbr.c printf/ft_putstr.c \
		printf/ft_putunsigned.c solong/so_long.c solong/ft_split.c \
		solong/ft_calloc.c solong/ft_flood_fill.c solong/free_utils.c \
		solong/errors.c solong/errors_utils.c solong/extra_errors.c \
		solong/so_long_utils.c solong/move.c solong/texture_move_utils.c \
		solong/texture.c

BONUS_SRCS = getnextline/get_next_line.c getnextline/get_next_line_utils.c \
		printf/ft_printf.c printf/ft_putchar.c printf/ft_putnbr_base.c \
		printf/ft_putnbr_base_p.c printf/ft_putnbr.c printf/ft_putstr.c \
		printf/ft_putunsigned.c bonus/so_long.c bonus/ft_split.c \
		bonus/ft_calloc.c bonus/ft_flood_fill.c bonus/free_utils.c \
		bonus/errors.c bonus/errors_utils.c bonus/extra_errors.c \
		bonus/so_long_utils.c bonus/move.c bonus/texture_move_utils.c \
		bonus/texture.c bonus/ft_itoa.c bonus/extra_utils.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

$(NAME): $(OBJS)
	@echo "\033[0;31mcompiling ${NAME}...\033[0m"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) $(INCLUDES)
	@echo "\033[0;32m${NAME} compiled!\033[0m"
	@echo

bonus: $(BONUS_OBJS)
	@echo "\033[0;31mcompiling ${BONUS_NAME}...\033[0m"
	@$(CC) $(FLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(MLXFLAGS) $(INCLUDES)
	@echo "\033[0;32m${BONUS_NAME} compiled!\033[0m"
	@echo

.c.o:
	@$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)
	
all: $(NAME)

clean:
	@echo "\033[0;31mdeleting objects...\033[0m"
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "\033[0;32mobjects deleted!\033[0m"
	@echo

fclean: clean
	@echo "\033[0;31mdeleting ${NAME} executable...\033[0m"
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "\033[0;32m${NAME} executable deleted!\033[0m"
	@echo

re: fclean all

.PHONY: all re clean fclean bonus