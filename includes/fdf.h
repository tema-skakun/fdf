/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:03 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/26 21:57:56 by fdarkhaw         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080
# define ZOOM_Z 1

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map
{
	float	x;
	float	y;
	int		z;
	int		rgb;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		str;
	int		col;
	int		zoom;
	int		shift_x;
	int		shift_y;
	void	*mlx;
	void	*win;
	int		flag;
	t_map	**map;
	t_vars	vars;
}				t_data;

int				validation_check(int argc, char **argv, t_data *data);
int				ft_errors(int i);
void			ft_free(char **p_str);
void			ft_free_data(t_data *data);
int				parser(char *av, t_data *data);
unsigned int	ft_htoi(const char *str);
int				len_space(char *str);
void			draw(t_data *data);
int				close_win(int keycode, t_data *data);
char			*ft_strjoin_gnl(char *s1, char const *s2);
char			*ft_strcpy(char *dest, char *src);
char			*get_next_line(int fd);
void			bresenham(float *x, float *y, int *z, t_data *data);

#endif
