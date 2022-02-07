/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:51:33 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/07 16:46:18 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_xyz	*xyz;

	if (validation_check(argc, argv))
		exit(1);
	xyz = new_struct(argv[1]);
	parser(argv[1], xyz);
	printf("\nok\n");
	exit(0);
	return (0);
}
