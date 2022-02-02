/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:03 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/02 12:28:51 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct s_xyz
{
	int	x;
	int	y;
	int	z;
	int	width;
	int	height;
}				t_xyz;

int		parser(int argc, char **argv);
int		ft_errors(int i);

char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strcpy(char *dest, char *src);
char	*get_next_line(int fd);

#endif
