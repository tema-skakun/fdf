/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:35:20 by jg                #+#    #+#             */
/*   Updated: 2022/02/09 16:05:34 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_xyz	*new_struct(char *av)
{
	t_xyz	*xyz;

	xyz = (t_xyz *)malloc(sizeof(t_xyz));
	xyz->project = 0;
	xyz->theta = 0.0;
	xyz->phi = 0.0;
	xyz->psi = 0.0;
	xyz->scale = 0.5;
	xyz->x_scale = 1;
	xyz->y_scale = 1;
	xyz->z_scale = 1;
	xyz->x_shift = 0.0;
	xyz->y_shift = 0.0;
	xyz->z_shift = 0.0;
	xyz->focal_dist = 7;
	xyz->r = 1;
	xyz->g = 1;
	xyz->b = 1;
	// xyz->id = mlx_init();
	// xyz->win = mlx_new_window(xyz->id, 100, 100, av);//(xyz->id, WIN_WIDTH, WIN_HEIGHT, av);
	return (xyz);
}
