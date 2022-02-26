/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:51:33 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/26 23:09:26 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){};
	if (validation_check(argc, argv, &data))
		exit(1);
	parser(argv[1], &data);
	data.shift_x = 800;
	data.shift_y = 250;
	data.vars.mlx = mlx_init();
	data.vars.win = mlx_new_window(data.vars.mlx, WIDTH, HEIGHT, argv[1]);
	draw(&data);
	// mlx_key_hook(data.vars.win, close_win, &data);
	mlx_hook(data.vars.win, 2, 1L << 0, close_win, &data);// не закрывается на крестик
	mlx_loop(data.vars.mlx);
	return (0);
}
