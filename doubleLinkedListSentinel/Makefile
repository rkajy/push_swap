# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/09 22:15:39 by radandri          #+#    #+#              #
#    Updated: 2025/10/09 22:43:53 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = list.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	createList.c \
		deleteFirstNode.c \
		deleteLastNode.c \
		deleteNode.c \
		initList.c \
		insertIntInHead.c \
		insertIntInTail.c \
		insertIntInTailChecked.c \
		insertNodeInHead.c \
		insertNodeInTail.c \
		isSortedStack.c \
		printList.c \
		searchIndexVal.c \
		searchNodeVal.c \
		swapFirst2Nodes.c \
		updateList.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(B_OBJS)
	ar rcs $(NAME) $(OBJS) $(B_OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

