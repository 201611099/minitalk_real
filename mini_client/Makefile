# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 10:49:43 by hyojlee           #+#    #+#              #
#    Updated: 2021/07/04 22:23:36 by lhj-unix         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = ../includes
NAME = client
MAKE = make
LIB_NAME = libft.a
LIB_DIR = ../libft
SRCS = client.c
BONUS = client_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(MAKE) -C $(LIB_DIR)/
	cp $(LIB_DIR)/$(LIB_NAME) $(LIB_NAME)
	$(CC) $(CFLAGS) -I$(INC) -o $(NAME) $(OBJ_FILES) $(LIB_NAME)

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	$(MAKE) clean -C $(LIB_DIR)/
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)/
	rm -f $(NAME) $(LIB_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
