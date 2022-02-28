/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:25:31 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/28 15:09:52 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	aplly_zoom(float *x, float *y, int zoom)
{
	x[0] = (x[0] * zoom);
	x[1] = (x[1] * zoom);
	y[0] = (y[0] * zoom);
	y[1] = (y[1] * zoom);
}

void	aplly_shift(float *x, float *y, t_data *data)
{
	x[0] = x[0] + data->shift_x;
	x[1] = x[1] + data->shift_x;
	y[0] = y[0] + data->shift_y;
	y[1] = y[1] + data->shift_y;
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(float *x, float *y, int *z, t_data *data)
{
	float	delta_x;
	float	delta_y;
	float	max;
	int		color;

	color = data->map[(int)y[0]][(int)x[0]].rgb;
	aplly_zoom(x, y, data->zoom);
	isometric(&x[0], &y[0], z[0] * data->zoom_z);
	isometric(&x[1], &y[1], z[1] * data->zoom_z);
	aplly_shift(x, y, data);
	delta_x = x[1] - x[0];
	delta_y = y[1] - y[0];
	max = fmaxf(fabsf(delta_x), fabsf(delta_y));
	delta_x /= max;
	delta_y /= max;
	while ((int)(x[0] - x[1]) || (int)(y[0] - y[1]))
	{
		if (x[0] > WIDTH || y[0] > HEIGHT || x[0] < 0 || y[0] < 0)
			return ;
		my_mlx_pixel_put(data, (int)x[0], (int)y[0], color);
		x[0] += delta_x;
		y[0] += delta_y;
	}
}
