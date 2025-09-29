# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 15:34:36 by radandri          #+#    #+#              #
#    Updated: 2025/09/28 05:31:34 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =push_swap
CC = cc
INC_DIR = includes
CFLAGS = -Wall -Wextra -Werror -g -I $(INC_DIR)
VALGRIND_ARGS = --leak-check=full --show-leak-kinds=all --track-origins=yes -s

LIBFT_PRINTF_DIR = libft_printf
LIBFT_PRINTF = $(LIBFT_PRINTF_DIR)/libftprintf.a

SRCS = push_swap_list.c \
		push_swap_parsing.c \
		push_swap_utils.c \
		push_swap_main.c \
		push_swap_move_a.c \
		push_swap_move_b.c \
		push_swap_move_both.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_PRINTF) $(NAME)

$(NAME): $(OBJS) $(LIBFT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PRINTF):
	$(MAKE) -C $(LIBFT_PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PRINTF_DIR) fclean

valgrind: $(NAME)
	valgrind $(VALGRIND_ARGS) ./$(NAME)

re: fclean all

.PHONY: all fclean clean re valgrind