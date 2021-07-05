# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 10:49:43 by hyojlee           #+#    #+#              #
#    Updated: 2021/07/05 11:40:43 by hyojlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = .minitalk
MAKE = make
MAKE_BONUS = make bonus
S_DIR = ./mini_server/
S_NAME = server
C_DIR = ./mini_client/
C_NAME = client

all: $(NAME)

$(NAME):
ifdef WITH_BONUS
	$(MAKE_BONUS) -C $(S_DIR)
	$(MAKE_BONUS) -C $(C_DIR)
else
	$(MAKE) -C $(S_DIR)
	$(MAKE) -C $(C_DIR)
endif
	cp $(S_DIR)$(S_NAME) $(S_NAME)
	cp $(C_DIR)$(C_NAME) $(C_NAME)
	@touch $(NAME)

bonus:
	$(MAKE)	WITH_BONUS=1 all

clean:
	$(MAKE) clean -C $(S_DIR)
	$(MAKE) clean -C $(C_DIR)
	rm -f $(NAME)

fclean: clean
	$(MAKE) fclean -C $(S_DIR)
	$(MAKE) fclean -C $(C_DIR)
	rm -f $(S_NAME) $(C_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
