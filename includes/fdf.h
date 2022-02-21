/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:03 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/18 17:49:06 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

# include "../libft/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		flag;
}				t_vars;

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
	void	*id;
	int		win;
}				t_xyz;

typedef struct s_map
{
	int	z;
	int	rgb;
	int	len;
}				t_map;

int		validation_check(int argc, char **argv);
t_xyz	*new_struct(char *av);
int		ft_errors(int i);
void	ft_free(char **p_str);
void	ft_free_map(t_map **map, int *num);
int		parser(char *av, int *num);
int		len_space(char *str);
void	draw_line(int *num);

char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strcpy(char *dest, char *src);
char	*get_next_line(int fd);

#endif
