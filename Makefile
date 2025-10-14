# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 15:34:36 by radandri          #+#    #+#              #
#    Updated: 2025/10/14 03:12:54 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
VALGRIND_ARGS = --leak-check=full --show-leak-kinds=all --track-origins=yes -s

LIBFT_PRINTF_DIR = libft_printf
LIBFT_PRINTF = $(LIBFT_PRINTF_DIR)/libftprintf.a

LIST_DIR = doubleLinkedListSentinel
LIST = $(LIST_DIR)/list.a

SRCS = moves/push_a.c \
		moves/push_b.c \
		moves/reverse_rotate_a.c \
		moves/reverse_rotate_b.c \
		moves/reverse_rotate_both_a_b.c \
		moves/rotate_a.c \
		moves/rotate_b.c \
		moves/rotate_both_a_b.c \
		moves/swap_a.c \
		moves/swap_b.c \
		moves/swap_both_a_b.c \
		push_swap_parsing.c \
		push_swap_utils.c \
		sort/push_swap_k_sort.c \
		sort/push_swap_radix.c \
		push_swap_normalize.c \
		push_swap_main.c \
		sort/sort_3.c \
		sort/sort_4.c \
		sort/sort_5.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_PRINTF) $(LIST) $(NAME)

$(NAME): $(OBJS) $(LIBFT_PRINTF) $(LIST)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PRINTF) $(LIST) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PRINTF):
	$(MAKE) -C $(LIBFT_PRINTF_DIR)

$(LIST):
	$(MAKE) -C $(LIST_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PRINTF_DIR) clean
	$(MAKE) -C $(LIST_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIST_DIR) fclean

valgrind: $(NAME)
	@ARG=$$(seq -500 500 | shuf | head -n 10); \
	valgrind $(VALGRIND_ARGS) ./$(NAME) $$ARG \

viz: $(NAME)
	echo "clone vizualizer"; \
	git clone https://github.com/o-reo/push_swap_visualizer; \
	cd push_swap_visualizer; \
	mkdir build; \
	cd build; \
	cmake ..; \
	make; \
	./bin/visualizer; \

test100: $(NAME)
	@ARG=$$(seq -500 500 | shuf | head -n 100); \
	echo "Testing with:" $$ARG; \
	./$(NAME) $$ARG > moves.txt; \
	echo "Moves saved to moves.txt"

test500: $(NAME)
	@ARG=$$(seq -500 500 | shuf | head -n 500); \
	echo "Testing with:" $$ARG; \
	./$(NAME) $$ARG > moves.txt; \
	echo "Moves saved to moves.txt"

test10: $(NAME)
	@ARG=$$(seq -500 500 | shuf | head -n 10); \
	echo "Testing with:" $$ARG; \
	./$(NAME) $$ARG | tee moves.txt; \
	echo "Moves saved to moves.txt"

re: fclean all

.PHONY: all fclean clean re valgrind viz test100 test500 test10