/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:51:33 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/25 20:54:39 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (validation_check(argc, argv, &data))
		exit(1);
	parser(argv[1], &data);
	draw(&data, argv[1]);
	// ft_free_data(&data);
	return (0);
}
