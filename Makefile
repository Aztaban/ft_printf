# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 10:47:16 by mjusta            #+#    #+#              #
#    Updated: 2025/06/02 14:04:10 by mjusta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRC = ft_printf.c ft_printf_number.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR) 
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re