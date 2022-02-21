/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:03 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/21 19:54:56 by fdarkhaw         ###   ########.fr       */
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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		flag;
}				t_vars;

typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	rgb;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		str;
	int		col;
	void	*mlx;
	void	*win;
	int		flag;
	t_map	**map;
}				t_data;

int		validation_check(int argc, char **argv, t_data *data);
int		ft_errors(int i);
void	ft_free(char **p_str);
void	ft_free_data(t_data *data);
int		parser(char *av, t_data *data);
int		len_space(char *str);
void	draw(t_data *data, char *av);

char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strcpy(char *dest, char *src);
char	*get_next_line(int fd);

#endif
