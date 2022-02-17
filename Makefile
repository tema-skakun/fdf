# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jg <jg@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 15:51:18 by fdarkhaw          #+#    #+#              #
#    Updated: 2022/02/17 13:04:26 by jg               ###   ########.fr        #
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
				./sources/draw.c\
				
		
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
		$(CC) $(CFLAGS) -Iminilibx_macos -I$(INC_DIR) -c $< -o $@ -MD

# %.o : %.c
# 		$(CC) -c $(CFLAGS) -I$(INC_DIR) $< -o $@ -MD

$(NAME)		: $(OBJ)
		make -C $(LIBFT_DIR)
		make bonus -C $(LIBFT_DIR)
		$(CC) $(OBJ) -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT_DIR)$(LIBFT)

# $(NAME)		: $(OBJ)
# 		make -C $(LIBFT_DIR)
# 		make bonus -C $(LIBFT_DIR)
# 		$(CC) -o $(NAME) $(CFLAGS) -I$(INC_DIR) $(OBJ) $(LIBFT_DIR)$(LIBFT)
		
clean:
		make -C $(LIBFT_DIR) clean
		make bonus -C $(LIBFT_DIR) clean
		rm -f $(OBJ) $(DEP) $(LIBFT_DIR)$(LIBFT)
		
fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re: fclean all

include $(wildcard $(DEP))
