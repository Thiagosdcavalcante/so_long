# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 18:51:18 by tsantana          #+#    #+#              #
#    Updated: 2024/03/23 17:42:49 by tsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -g3
LIBMLX	:= ./libs/mlx42

HEADERS	= -I $(LIBMLX)/include -I ./src
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= main.c src/map_checker.c src/list_work.c src/objects.c src/size_definition.c src/so_long.c \
		   src/put_elements.c src/free.c src/so_long_utils.c src/cllct_work.c src/flood_fill.c \
		   src/so_long_utils2.c
BNS		= src/bonus/main_bonus.c src/bonus/cllct_work_bonus.c src/bonus/flood_fill_bonus.c \
		   src/bonus/free_bonus.c src/bonus/img_utils_bonus.c src/bonus/list_work_bonus.c \
		   src/bonus/map_checker_bonus.c src/bonus/objects_bonus.c src/bonus/put_elements_bonus.c \
		   src/bonus/size_definition_bonus.c src/bonus/so_long_bonus.c src/bonus/so_long_utils_bonus.c \
		   src/bonus/so_long_utils2_bonus.c src/bonus/ft_itoa.c \
		   src/bonus/ft_itoa_utils.c
BHEADERS	= -I $(LIBMLX)/include -I ./src/bonus/
OBJS	= $(SRCS:%.c=%.o)
BOBJS	= $(BNS:%.c=%.o)
DELETE	= $(BOBJS)

ifdef	WITH_BONUS
	DELETE := $(OBJS)
	SRCS := $(BNS)
	OBJS := $(BOBJS)
	HEADERS := $(BHEADERS)
endif

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@rm -rf $(DELETE)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(BOBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

bonus:
	@make WITH_BONUS=YES --no-print-directory

.PHONY: all, clean, fclean, re, libmlx, bonus
