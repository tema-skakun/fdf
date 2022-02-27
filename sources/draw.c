/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:55:51 by jg                #+#    #+#             */
/*   Updated: 2022/02/27 22:27:32 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		j = 0;
		while (j < data->col - 1)
		{
			x[0] = data->map[i][j].x;
			y[0] = data->map[i][j].y;
			z[0] = data->map[i][j].z;
			x[1] = data->map[i][j + 1].x;
			y[1] = data->map[i][j].y;
			z[1] = data->map[i][j + 1].z;
			bresenham(x, y, z, data);
			j++;
		}
		i++;
	}
}

void	draw_col(t_data *data)
{
	float	x[2];
	float	y[2];
	int		z[2];
	int		i;
	int		j;

	j = 0;
	while (j < data->col)
	{
		i = 0;
		while (i < data->str - 1)
		{
			x[0] = data->map[i][j].x;
			y[0] = data->map[i][j].y;
			z[0] = data->map[i][j].z;
			x[1] = data->map[i][j].x;
			y[1] = data->map[i + 1][j].y;
			z[1] = data->map[i + 1][j].z;
			bresenham(x, y, z, data);
			i++;
		}
		j++;
	}
}

void	find_zoom(t_data *data)
{
	int	z1;
	int	z2;

	z1 = 0;
	z2 = 0;
	if (data->col != 0)
		z1 = (WIDTH) / (data->col);
	if (data->str != 0)
		z2 = (HEIGHT) / (data->str);
	data->zoom = (int)fminf((float)z1, (float)z2);
	if ((float)data->col / (float)data->str > 1.5)
		data->zoom -= 20;
	// data->zoom = 20;
}

void	draw(t_data *data)
{
	data->img = mlx_new_image(data->vars.mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	mlx_clear_window(data->vars.mlx, data->vars.win);
	if (data->col != 1 || data->str != 1)
	{
		draw_str(data);
		draw_col(data);
	}
	else
		my_mlx_pixel_put(data, data->shift_x, data->shift_y, \
		data->map[0][0].rgb);
	mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->img, 0, 0);
	mlx_destroy_image(data->vars.mlx, data->img);
}
