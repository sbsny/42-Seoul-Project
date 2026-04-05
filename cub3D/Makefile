# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 13:04:28 by seonyun           #+#    #+#              #
#    Updated: 2023/02/20 17:38:06 by seonyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = ./libft
SRC = 	main.c check_files.c check_wall.c draw.c \
		error.c event.c free_utils.c initiate.c mapping.c parsing1.c raycasting.c \
	 	start_mlx.c texture.c parsing2.c
SRCB = bonus/main_bonus.c bonus/minimap_bonus.c bonus/check_wall_bonus.c bonus/draw_bonus.c bonus/check_files_bonus.c \
		bonus/error_bonus.c bonus/event_bonus.c bonus/free_utils_bonus.c bonus/initiate_bonus.c bonus/mapping_bonus.c \
		bonus/parsing1_bonus.c bonus/raycasting_bonus.c \
	 	bonus/start_mlx_bonus.c bonus/texture_bonus.c bonus/parsing2_bonus.c bonus/mouse_bonus.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
NAME = cub3D
NAMEB = cub3D_bonus

MLXDIR = ./mlx

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
		$(MAKE) all -C $(LIBDIR)
		$(MAKE) -C $(MLXDIR)
		$(CC) -o $(NAME) $(OBJ) -L $(LIBDIR) -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

bonus: $(NAMEB)

$(NAMEB) : $(OBJB)
		$(MAKE) all -C $(LIBDIR)
		$(MAKE) -C $(MLXDIR)
		$(CC) -o $(NAMEB) $(OBJB) -L $(LIBDIR) -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

clean :
		$(MAKE) -C $(LIBDIR) clean
		$(MAKE) -C $(MLXDIR) clean
		rm -f $(OBJB)
		rm -f $(OBJ)

fclean : clean
		$(MAKE) -C $(LIBDIR) fclean
		rm -f $(NAME)
		rm -f $(NAMEB)

re :
		make fclean
		make all

.PHONY: all clean fclean re bonus
