# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 10:49:43 by hyojlee           #+#    #+#              #
#    Updated: 2021/07/02 22:01:05 by lhj-unix         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = .minitalk
MAKE = make
S_DIR = ./mini_server/
S_NAME = server
C_DIR = ./mini_client/
C_NAME = client

all: $(NAME)

$(NAME):
	$(MAKE) -C $(S_DIR)
	cp $(S_DIR)$(S_NAME) $(S_NAME)
	$(MAKE) -C $(C_DIR)
	cp $(C_DIR)$(C_NAME) $(C_NAME)
	touch $(NAME)

clean:
	$(MAKE) clean -C $(S_DIR)
	$(MAKE) clean -C $(C_DIR)

fclean: clean
	$(MAKE) fclean -C $(S_DIR)
	$(MAKE) fclean -C $(C_DIR)
	rm -f $(NAME) $(S_NAME) $(C_NAME)

re: fclean all

.PHONY: all clean fclean re
