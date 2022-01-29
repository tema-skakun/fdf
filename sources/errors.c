/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:30:54 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/01/29 19:45:04 by fdarkhaw         ###   ########.fr       */
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
		ft_putendl_fd("cmd1 or cmd2 does not exist", 2);
	else if (i == 3)
		ft_putendl_fd("file1 does not exist or is closed for reading", 2);
	else if (i == 4)
		perror("Error");
	return (1);
}
