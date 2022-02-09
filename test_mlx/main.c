/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:04:12 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/09 10:30:07 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		flag;
}				t_vars;


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

// int	main(void)
// {
// 	t_vars	vars;
// 	t_data	img;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1000, 500, "Hello world!");
// 	img.img = mlx_new_image(vars.mlx, 1000, 500);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
// 								&img.line_length, &img.endian);
// 	my_mlx_pixel_put(&img, 500, 250, 0x00FF0000);
// 	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 	mlx_hook(vars.win, 17, 1L << 0, close_, &vars);// закрывает окно на крестик
// 	mlx_hook(vars.win, 2, 1L << 0, close_, &vars);// закрывает окно на esc
// 	// проработать ф-цию close_
// 	mlx_loop(vars.mlx);
// }

int	mouse_hook(int keycode, t_vars *vars)
{
	void	*v;

	v = vars->win;
	if (keycode == 1)
		printf("left\n");
	else
		printf("Hello from mouse_hook!\n");
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	void	*v;

	v = vars->win;
	printf("Hello from key_hook!\n");
	return (keycode);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
