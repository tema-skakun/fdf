# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jg <jg@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 15:51:18 by fdarkhaw          #+#    #+#              #
#    Updated: 2022/02/09 05:56:49 by jg               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test

INC_DIR		= ./includes/

SRCS		=	main.c\
				bitshifting.c\
				# char_to_int.c\

OBJ			= $(SRCS:.c=.o)
DEP			= $(SRCS:.c=.d)

CFLAGS		= -Wall -Werror -Wextra
CC			= cc

.PHONY		: all clean fclean re

all			: $(NAME)

# __to_launch_at_school_21__
# %.o : %.c
# 		$(CC) $(CFLAGS) -Imlx -c $< -o $@

# $(NAME)		: $(OBJ)
# 		$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -Iminilibx_macos -c $< -o $@

$(NAME)		: $(OBJ)
		$(CC) $(OBJ) -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		rm -f $(OBJ) $(DEP) $(LIBFT_DIR)$(LIBFT)
		
fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re: fclean all

include $(wildcard $(DEP))
