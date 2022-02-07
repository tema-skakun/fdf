/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:03 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/07 09:57:29 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct s_xyz
{
	int		x;
	int		y;
	int		z;
	int		width;
	int		height;
	int		project;
	float	theta;
	float	phi;
	float	psi;
	float	scale;
	int		x_scale;
	int		y_scale;
	int		z_scale;
	float	x_shift;
	float	y_shift;
	float	z_shift;
	int		focal_dist;
	int		r;
	int		g;
	int		b;
	int		id;
	int		win;
}				t_xyz;

int		validation_check(int argc, char **argv);
t_xyz	*new_struct(char *av);
int		ft_errors(int i);
void	ft_free(char **p_str);
int		parser(char *av, t_xyz *xyz);

char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strcpy(char *dest, char *src);
char	*get_next_line(int fd);

#endif
