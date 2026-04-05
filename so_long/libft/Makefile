# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 13:47:02 by seonyun           #+#    #+#              #
#    Updated: 2022/09/24 00:32:09 by seonyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
 		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
 		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
 		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c	ft_isprint.c \
 		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_striteri.c\
 		ft_substr.c	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c	\
 		ft_putchar_fd.c	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c \
		ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
 			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

ifdef IF_BONUS
	OBJS += $(OBJS_BONUS)
endif

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus:
	make all IF_BONUS=1

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re