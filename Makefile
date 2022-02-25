# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 15:51:18 by fdarkhaw          #+#    #+#              #
#    Updated: 2022/02/25 22:12:30 by fdarkhaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

INC_DIR		= ./includes/
LIBFT_DIR	= ./libft/
LIBFT		= libft.a

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

# __to_launch_at_home__
%.o : %.c
		$(CC) $(CFLAGS) -Iminilibx_macos -I $(INC_DIR) -c $< -o $@ -MD

$(NAME)		: $(OBJ)
		make -C $(LIBFT_DIR)
		make bonus -C $(LIBFT_DIR)
		$(CC) $(OBJ) -fsanitize=address -g -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit\
		-o $(NAME) $(LIBFT_DIR)$(LIBFT)
#убить санитайзер
		
clean:
		make -C $(LIBFT_DIR) clean
		make bonus -C $(LIBFT_DIR) clean
		rm -f $(OBJ) $(DEP) $(LIBFT_DIR)$(LIBFT)
		
fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re: fclean all

include $(wildcard $(DEP))
