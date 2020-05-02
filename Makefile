# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/02 17:13:09 by dsandshr          #+#    #+#              #
#    Updated: 2020/05/02 17:21:43 by dsandshr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := asm

OBJ_DIR := ./bin

LFT_DIR := ./lib/libft

LFT_PRINTF_DIR := ./lib/ft_printf

HEADERS_DIR := ./include $(LFT_DIR) $(LFT_PRINTF_DIR)/includes

DIR_SRC := ./src

SRC_ASM := asm.c

OBJ_ASM := $(SRC_ASM:.c=.o)

HEADERS := asm.h libft.h ft_printf.h op.h

CC := gcc -Wall -Werror -Wextra -O3

vpath %.c $(DIR_SRC)
vpath %.o $(OBJ_DIR)
vpath %.h $(HEADERS_DIR)
vpath %.a $(LFT_DIR) $(LFT_PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJ_ASM)
	@$(CC) $(addprefix $(OBJ_DIR)/, $(OBJ_ASM)) $(INCLUDE) -lft -L $(LFT_DIR) -lftprintf -L $(LFT_PRINTF_DIR) -o $@
	@printf "\r\e[J\e[32m$@\e[0m done!\n\e[?25h"

$(OBJ_ASM): %.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $< $(addprefix -I,$(HEADERS_DIR)) -o $(OBJ_DIR)/$@
	@printf "\r\e[?25l\e[Jcompiling \e[32m$(notdir $<)\e[0m"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all