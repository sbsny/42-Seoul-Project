# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 17:54:13 by seonyun           #+#    #+#              #
#    Updated: 2022/09/11 17:54:16 by seonyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_OBJS = server.o
CLIENT_OBJS = client.o

SERVER_OBJS_BONUS = server_bonus.o
CLIENT_OBJS_BONUS = client_bonus.o

ifdef IF_BONUS
	S_OBJ = $(SERVER_OBJS_BONUS)
	C_OBJ = $(CLIENT_OBJS_BONUS)
else
	S_OBJ = $(SERVER_OBJS)
	C_OBJ = $(CLIENT_OBJS)
endif

CC = cc
CFLAG = -Wall -Wextra -Werror

NAME = minitalk
SERVER = server
CLIENT = client

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : $(S_OBJ)
	$(CC) $(CFLAG) $< -o $@

$(CLIENT) : $(C_OBJ)
	$(CC) $(CFLAG) $< -o $@

bonus :
	make all IF_BONUS=1

clean :
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)

fclean : clean
	rm -rf $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all clean fclean re bonus