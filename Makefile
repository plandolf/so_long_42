# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plandolf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 10:46:15 by plandolf          #+#    #+#              #
#    Updated: 2023/09/29 10:56:26 by plandolf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
LIBFT_NAME	:= ./inc/libft_nob/libft.a
CFLAGS	:= -Wextra -Wall -Werror -g -fsanitize=address
LIBMLX	:= ./inc/mlx_linux
LIBFT_SRCS = $(shell find ./inc/libft_nob -iname "*.c")
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
HEADERS	:= -I ./inc -I $(LIBMLX)/
LIBS	:= -L$(LIBMLX) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}
SUPP_LIBS :=-L./inc/libft_nob -lft

all: $(NAME) $(LIBFT_NAME)

$(NAME) : $(OBJS) $(LIBFT_NAME)
	$(MAKE) -C ./inc/mlx_linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(SUPP_LIBS) -o $(NAME)

$(LIBFT_NAME): $(LIBFT_OBJS)
	ar -rcs $@ $^

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT_NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
