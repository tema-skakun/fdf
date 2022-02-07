# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jg <jg@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 15:51:18 by fdarkhaw          #+#    #+#              #
#    Updated: 2022/02/07 14:11:13 by jg               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

INC_DIR		= ./includes/
LIBFT_DIR	= ./libft/
LIBFT		= libft.a

# INC_MINILIBX = -I minilibx
# LINK_MINILIBX = -L minilibx -lmlx
# MINILIBX = $(INC_MINILIBX) $(LINK_MINILIBX)
# MINILIBX = ./minilibx/libmlx.a

SRCS		=	./sources/main.c\
				./sources/validation_check.c\
				./sources/errors.c\
				./sources/get_next_line.c\
				./sources/get_next_line_utils.c\
				./sources/parser.c\
				./sources/struct.c\
		
OBJ			= $(SRCS:.c=.o)
DEP			= $(SRCS:.c=.d)

CFLAGS		= -Wall -Werror -Wextra

.PHONY		: all clean fclean re

all			: $(NAME)

$(NAME)		: $(OBJ)
		make -C $(LIBFT_DIR)
		make bonus -C $(LIBFT_DIR)
		cc -o $(NAME) $(CFLAGS) -I$(INC_DIR) $(OBJ) $(LIBFT_DIR)$(LIBFT)

%.o : %.c
		cc -c $(CFLAGS) -I$(INC_DIR) $< -o $@ -MD
		
clean:
		make -C $(LIBFT_DIR) clean
		make bonus -C $(LIBFT_DIR) clean
		rm -f $(OBJ) $(DEP) $(LIBFT_DIR)$(LIBFT)
		
fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re: fclean all

include $(wildcard $(DEP))
