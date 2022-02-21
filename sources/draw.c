/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:55:51 by jg                #+#    #+#             */
/*   Updated: 2022/02/21 19:56:14 by fdarkhaw         ###   ########.fr       */
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

void	bresenham(double *x, double *y, t_data *data)
{
	double	signY;
	double	signX;
	double	f;
	double	X;
	double	Y;

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
	my_mlx_pixel_put(data, (int)X, (int)Y, 0x00FF0000);// отобразить точку
	if (fabs(y[1] - y[0]) < fabs(x[0] - x[1]))
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
			my_mlx_pixel_put(data, (int)X, (int)Y, 0x00FF0000);// отобразить точку
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
			my_mlx_pixel_put(data, (int)X, (int)Y, 0x00FF0000);// отобразить точку
		}
	}
}

void	draw(t_data *data, char *av)
{
	double	x[2];
	double	y[2];
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 600, av);
	data->img = mlx_new_image(vars.mlx, 1000, 600);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	x[0] = 500;
	y[0] = 100;
	x[1] = 700;
	y[1] = 200;
	// draw_str(data);
	bresenham(x, y, data);
	mlx_put_image_to_window(vars.mlx, vars.win, data->img, 0, 0);
	mlx_hook(vars.win, 17, 1L << 0, close_, &vars);// закрывает окно на крестик, но сегается
	mlx_hook(vars.win, 2, 1L << 0, close_, &vars);// закрывает окно на esc
	// проработать ф-цию close_
	mlx_loop(vars.mlx);
}
