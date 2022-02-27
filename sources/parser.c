/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:31:34 by jg                #+#    #+#             */
/*   Updated: 2022/02/27 21:52:57 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_zoom_z(t_data *data)
{
	int	min_z;
	int	max_z;
	int	iterator[2];

	max_z = -2147483648;
	min_z = 2147483647;
	iterator[0] = 0;
	while (iterator[0] < data->str)
	{
		iterator[1] = 0;
		while (iterator[1] < data->col)
		{
			if (min_z > data->map[iterator[0]][iterator[1]].z)
				min_z = data->map[iterator[0]][iterator[1]].z;
			if (max_z < data->map[iterator[0]][iterator[1]].z)
				max_z = data->map[iterator[0]][iterator[1]].z;
			iterator[1]++;
		}
		iterator[0]++;
	}
	data->zoom_z = max_z - min_z;
	if (data->zoom_z > 20)
		data->zoom_z = 1;
}

void	get_xy(t_data *data)
{
	int		i;
	int		j;

	i = data->str;
	while (--i + 1)
	{
		j = data->col;
		while (--j + 1)
		{
			data->map[i][j].y = (float)i;
			data->map[i][j].x = (float)j;
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
	get_zoom_z(data);
	return (0);
}
