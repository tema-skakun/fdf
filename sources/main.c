/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:51:33 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/18 17:48:13 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	int	num[2];

	if (validation_check(argc, argv))
		exit(1);
	parser(argv[1], num);
	printf("\nok\n");
	draw_line(num);
	exit(0);
	return (0);
}
