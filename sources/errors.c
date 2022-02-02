/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:30:54 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/01 17:14:55 by jg               ###   ########.fr       */
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
		ft_putendl_fd("file1 does not exist or is closed for reading", 2);
	else if (i == 4)
		perror("Error");
	exit (1);
}
