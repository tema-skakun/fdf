/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:54:21 by jg                #+#    #+#             */
/*   Updated: 2022/02/28 16:03:12 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_and_zoom(int key, t_data *data)
{
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 126)
		data->shift_y -= 10;
	if (key == 24)
		data->zoom_z += 1;
	if (key == 27)
		data->zoom_z -= 1;
	if (key == 34)
		data->zoom += 1;
	if (key == 31)
		data->zoom -= 1;
}

int	image_manag(int keycode, t_data *data)
{
	if (keycode == 53)
		exit (0);
	if ((keycode >= 123 && keycode <= 126) || keycode == 24 || keycode == 27 \
	|| keycode == 34 || keycode == 31)
	{
		move_and_zoom(keycode, data);
		draw(data);
	}
	if (keycode >= 0 && keycode <= 279)
		keycode++;
	else
		exit (0);
	return (0);
}
