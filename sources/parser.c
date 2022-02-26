/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:31:34 by jg                #+#    #+#             */
/*   Updated: 2022/02/26 22:53:46 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_xy(t_data *data)
{
	float	step;
	int		i;
	int		j;

	step = 1;
	i = data->str;
	while (--i + 1)
	{
		j = data->col;
		while (--j + 1)
		{
			data->map[i][j].y = step * (i);
			data->map[i][j].x = step * (j);
		}
	}
}

void	write_z_to_map(t_map *map, char **points)
{
	int	i;
	int	p;

	i = 0;
	while (points[i])
	{
		p = 0;
		map[i].z = ft_atoi(points[i], &p);
		map[i].rgb = 0x00FFFFFF;
		if (p)
			map[i].rgb = ft_htoi(points[i] + p + 3);
		i++;
	}
}

void	points_parser(int fd, t_data *data)
{
	int		i;
	char	*line;
	char	**points;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		points = ft_split(line, ' ');
		free(line);
		data->map[i] = malloc(sizeof(t_map) * data->col);
		if (!data->map[i])
		{
			ft_free(points);
			ft_free_data(data);
			ft_errors(3);
		}
		write_z_to_map(data->map[i], points);
		ft_free(points);
		i++;
	}
}

int	parser(char *av, t_data *data)
{
	int		fd;

	data->map = malloc(sizeof(t_map *) * data->str);
	if (!data->map)
		ft_errors(3);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_errors(3);
	points_parser(fd, data);
	if (close(fd) == -1)
		ft_errors(3);
	get_xy(data);
	return (0);
}
