/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:55:51 by jg                #+#    #+#             */
/*   Updated: 2022/02/25 22:27:11 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

int	close_(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	printf("keycode = %d\n", keycode);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(float *x, float *y, int color, t_data *data)//[1:1] [3:12]
{
	float	delta_x;
	float	delta_y;
	float	max;

	isometric(&x[0], &y[0], data->map[(int)y[0]][(int)x[0]].z);
	isometric(&x[1], &y[1], data->map[(int)y[1]][(int)x[1]].z);
	x[0] += 600;
	y[0] += 400;
	x[1] += 600;
	y[1] += 400;
	delta_x = x[1] - x[0];// хранит дельту
	delta_y = y[1] - y[0];
	// printf("1 delta_x = %f, delta_y = %f\n", delta_x, delta_y);
	max = fmaxf(fabsf(delta_x), fabsf(delta_y));// максимальная дельта по модулю
	// printf("max = %f\n", max);
	delta_x /= max;//привожу к еденице со знаком или без
	delta_y /= max;
	// printf("2 delta_x = %f, delta_y = %f\n", delta_x, delta_y);
	while ((int)(x[0] - x[1]) || (int)(y[0] - y[1]))
	{
		if (x[0] >= 1200 || y[0] >= 1200)// || x[0] < 0 || y[0] < 0)
			return;// не позволяет выйти за поле
		my_mlx_pixel_put(data, (int)x[0], (int)y[0], color);
		x[0] += delta_x;
		y[0] += delta_y;
	}
}

void	draw_str(t_data *data)
{
	float	x[2];
	float	y[2];
	int		z[2];
	int		i;
	int		j;

	i = 0;
	while (i < data->str)
	{
		j = 1;
		while (j < data->col)
		{
			x[0] = data->map[i][j].x * ZOOM;
			y[0] = data->map[i][j].y * ZOOM;
			z[0] = data->map[i][j].z * ZOOM;
			x[1] = data->map[i][j + 1].x * ZOOM;
			y[1] = data->map[i][j].y * ZOOM;
			z[1] = data->map[i][j + 1].z * ZOOM;
			bresenham(x, y, data->map[i][j].rgb, data);
			j++;
		}
		i++;
	}
}

void	draw_col(t_data *data)
{
	float	x[2];
	float	y[2];
	int	z[2];
	int	i;
	int	j;

	i = 0;
	while (i < data->str - 1)
	{
		j = 0;
		while (j < data->col)
		{
			x[0] = data->map[i][j].x  * ZOOM;
			y[0] = data->map[i][j].y  * ZOOM;
			z[0] = data->map[i][j].z  * ZOOM;
			x[1] = data->map[i][j].x  * ZOOM;
			y[1] = data->map[i + 1][j].y  * ZOOM;
			z[1] = data->map[i][j + 1].z  * ZOOM;
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
	vars.win = mlx_new_window(vars.mlx, 1200, 1200, av);
	data->img = mlx_new_image(vars.mlx, 1200, 1200);
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
