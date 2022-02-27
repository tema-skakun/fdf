/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:30:54 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/27 15:37:07 by jg               ###   ########.fr       */
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
	else if (i == 4)
		ft_putendl_fd("The first line in the file is empty. Exiting.", 2);
	else if (i == 5)
		ft_putendl_fd("The file is empty. Exiting.", 2);
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

void	ft_free_data(t_data *data)
{
	int	i;

	if (data->map != NULL)
	{
		i = 0;
		while (i < data->col)
			free(data->map[i++]);
		free(data->map);
	}
}
