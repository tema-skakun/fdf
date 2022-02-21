/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:30:54 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/18 18:08:41 by jg               ###   ########.fr       */
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

void	ft_free_map(t_map **map, int *num)
{
	int	i;

	if (map != NULL)
	{
		i = 0;
		while (i < num[0])
			free(map[i++]);
		free(map);
	}
}
