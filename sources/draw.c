/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:55:51 by jg                #+#    #+#             */
/*   Updated: 2022/02/23 14:21:15 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (keycode);
}

void	bresenham(int *x, int *y, int color, t_data *data)
{
	int	signY;
	int	signX;
	int	f;
	int	X;
	int	Y;

	if ((y[1] - y[0]) < 0)
		signY = -1;
	else
		signY = 1;
	if ((x[0] - x[1]) < 0)
		signX = -1;
	else
		signX = 1;
	f = 0;
	X = x[0];
	Y = y[0];
	my_mlx_pixel_put(data, X, Y, color);// отобразить точку
	if (abs(y[1] - y[0]) < abs(x[0] - x[1]))
	{
		while (X != x[1] || Y != y[1])
		{
			f += (y[1] - y[0]) * signY;
			if (f > 0)
			{
				f -= (x[0] - x[1]) * signX;
				Y += signY;
			}
			X -= signX;
			my_mlx_pixel_put(data, X, Y, color);// отобразить точку
		}
	}
	else
	{
		while (X != x[1] || Y != y[1])
		{
			f += (x[0] - x[1]) * signX;
			if (f > 0)
			{
				f -= (y[1] - y[0]) * signY;
				X -= signX;
			}
			Y += signY;
			my_mlx_pixel_put(data, X, Y, color);// отобразить точку
		}
	}
}

void	draw_str(t_data *data)
{
	int	x[2];
	int	y[2];
	int	i;
	int	j;

	i = 0;
	while (i < data->str)
	{
		j = 0;
		while (j < data->col - 1)
		{
			x[0] = data->map[i][j].x;
			y[0] = data->map[i][j].y;
			x[1] = data->map[i][j + 1].x;
			y[1] = data->map[i][j].y;
			bresenham(x, y, data->map[i][j].rgb, data);
			// printf("str rgb = %d\n", data->map[i][j].rgb);
			j++;
		}
		i++;
	}
}

void	draw_col(t_data *data)
{
	int	x[2];
	int	y[2];
	int	i;
	int	j;

	i = 0;
	while (i < data->str - 1)
	{
		j = 0;
		while (j < data->col)
		{
			x[0] = data->map[i][j].x;
			y[0] = data->map[i][j].y;
			x[1] = data->map[i][j].x;
			y[1] = data->map[i + 1][j].y;
			bresenham(x, y, data->map[i][j].rgb, data);
			j++;
		}
		i++;
	}
}

void	draw(t_data *data, char *av)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 600, av);
	data->img = mlx_new_image(vars.mlx, 1000, 600);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	draw_str(data);
	draw_col(data);
	mlx_put_image_to_window(vars.mlx, vars.win, data->img, 0, 0);
	mlx_hook(vars.win, 17, 1L << 0, close_, &vars);// закрывает окно на крестик, но сегается
	mlx_hook(vars.win, 2, 1L << 0, close_, &vars);// закрывает окно на esc
	// проработать ф-цию close_
	mlx_loop(vars.mlx);
}
