# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 18:51:18 by tsantana          #+#    #+#              #
#    Updated: 2024/03/20 19:33:40 by tsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
NAMEB	:= so_long_bonus
CFLAGS	:= -Wextra -Wall -Werror -g3
LIBMLX	:= ./libs/mlx42

HEADERS	:= -I $(LIBMLX)/include -I ./src
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= main.c src/map_checker.c src/list_work.c src/objects.c src/size_definition.c src/so_long.c \
		   src/put_elements.c src/free.c src/so_long_utils.c src/cllct_work.c src/flood_fill.c 
BNS		:= src/bonus/main_bonus.c src/bonus/cllct_work_bonus.c src/bonus/floof_fill_bonus.c \
		   src/bonus/free_bonus.c src/bonus/img_utils_bonus.c src/bonus/list_work_bonus.c \
		   src/bonus/map_checker_bonus.c src/bonus/objects_bonus.c src/bonus/put_elements_bonus.c \
		   src/bonus/size_definition_bonus.c src/bonus/so_long_bonus.c src/so_long_utils_bonus.c 
BHEADERS	:= -I $(LIBMLX)/include -I ./src/bonus/
OBJS	:= ${SRCS:%.c=%.o}
BOBJS	:= ${BNS:%.C=%.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(NAMEB): $(BOBJS)
	@$(CC) $(CFLAGS) $(BOBJS) $(LIBS) $(BHEADERS) -o $(NAMEB)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(BOBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

bonus: fclean $(NAMEB)

.PHONY: all, clean, fclean, re, libmlx, bonus
