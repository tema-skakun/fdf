/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:51:33 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/27 22:28:07 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	events(t_data *data)
{
	mlx_hook(data->vars.win, 17, 1L << 0, image_manag, data);
	mlx_hook(data->vars.win, 2, 1L << 0, image_manag, data);
	mlx_loop(data->vars.mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){};
	if (validation_check(argc, argv, &data))
		exit(1);
	parser(argv[1], &data);
	data.shift_x = (int)(WIDTH / 2.4);
	data.shift_y = (int)(HEIGHT / 4.32);
	data.vars.mlx = mlx_init();
	data.vars.win = mlx_new_window(data.vars.mlx, WIDTH, HEIGHT, argv[1]);
	find_zoom(&data);
	draw(&data);
	events(&data);
	return (0);
}
