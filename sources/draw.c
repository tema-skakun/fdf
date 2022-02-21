/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:55:51 by jg                #+#    #+#             */
/*   Updated: 2022/02/18 20:09:16 by jg               ###   ########.fr       */
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

void	bresenham(double *x, double *y, t_data img)
{
	double		signY;
	double		signX;
	double		f;
	double		X;
	double		Y;

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
	my_mlx_pixel_put(&img, (int)X, (int)Y, 0x00FF0000);// отобразить точку
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
			my_mlx_pixel_put(&img, (int)X, (int)Y, 0x00FF0000);// отобразить точку
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
			my_mlx_pixel_put(&img, (int)X, (int)Y, 0x00FF0000);// отобразить точку
		}
	}
}

int	find_step(int str, int col)
{
	int	s1;
	int	s2;

	s1 = (1000 - 50) / (col);// - 1);
	s2 = (600 - 50) / (str);// - 1);
	if (s1 < s2)
		return (s1);
	else
		return (s2);
}

void	calculate_xy(int str, int col)
{
	double	x[500];
	double	y[500];
	int		step;
	int		i;
	int		j;

	step = find_step(str, col);
	i = str - 1;
	j = col - 1;
	while (str)//заполню координаты У
	{
		y[str - 1] = step * str + (600 / 2) - (step * (i + 2) / 2);
		str--;
	}
	while (col)//заполню координаты Х
	{
		x[col - 1] = step * col + ((1000 / 2) - (step * (j + 2) / 2));
		col--;
	}
	printf("step = %d\n", step);
	while (j + 1)//печать координаты Х
	{
		printf("x[%d] = %f\n", j, x[j]);
		j--;
	}
	while (i + 1)//печать координаты У
	{
		printf("y[%d] = %f\n", i, y[i]);
		i--;
	}
}

void	draw_line(int *num)//рисует линию
{
	double	x[2];
	double	y[2];
	t_vars	vars;
	t_data	img;

	calculate_xy(num[0], num[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 600, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1000, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
									&img.line_length, &img.endian);
	x[0] = 500;
	y[0] = 100;
	x[1] = 700;
	y[1] = 200;
	bresenham(x, y, img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 1L << 0, close_, &vars);// закрывает окно на крестик, но сегается
	mlx_hook(vars.win, 2, 1L << 0, close_, &vars);// закрывает окно на esc
	// проработать ф-цию close_
	mlx_loop(vars.mlx);
}
