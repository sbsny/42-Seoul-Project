# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 13:45:19 by seonyun           #+#    #+#              #
#    Updated: 2022/09/24 08:34:20 by seonyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

SRC =	./srcs/close_free.c \
		./srcs/error_manage.c \
		./srcs/display.c \
		./srcs/key_function.c \
		./srcs/map_parsing.c \
		./srcs/main.c \

OBJ = ${SRC:.c=.o}
NAME = so_long
LIBFTDIR = ./libft
MLXDIR = ./mlx
INLIBFT = -L./libft -lft
INMLX = -L./mlx -lmlx

%.o : %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	$(MAKE) -C $(LIBFTDIR) all
	$(MAKE) -C $(MLXDIR) all
	${CC} ${FLAGS} ${OBJ} ${INLIBFT} ${INMLX} -framework OpenGL -framework AppKit -o ${NAME}

clean:
	${RM} ${OBJ}
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re