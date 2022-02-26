/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:30:54 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/26 23:08:30 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_errors(int i)
{
	if (i == 1)
	{
		ft_putendl_fd("Incorrect number of arguments", 2);
		ft_putendl_fd("Instance: ./fdf filename.fdf", 2);
	}
	else if (i == 2)
		ft_putendl_fd("Found wrong line length. Exiting.", 2);
	else if (i == 3)
		perror("Error");
	exit (1);
}

void	ft_free(char **p_str)
{
	int	i;

	i = 0;
	if (p_str != NULL)
	{
		while (p_str[i])
			free(p_str[i++]);
		free(p_str);
	}
}

void	ft_free_data(t_data *data)
{
	int	i;

	if (data->map != NULL)
	{
		i = 0;
		while (i < data->col)
			free(data->map[i++]);
		free(data->map);
	}
}

void	move(int key, t_data *data)
{
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 126)
		data->shift_y -= 10;
}

int	close_win(int keycode, t_data *data)
{
	if (keycode == 53)
		exit (0);
	if (keycode >= 123 || keycode <= 126)
	{
		move(keycode, data);
		printf("%d\n", keycode);
		// mlx_clear_window(data->vars.mlx, data->vars.win);
		draw(data);
	}
	if (keycode >= 0 && keycode <= 273)
		keycode++;
	else
		exit (0);
	return (0);
}
