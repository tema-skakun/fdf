/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:31:34 by jg                #+#    #+#             */
/*   Updated: 2022/02/21 19:26:11 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_map(t_data *data)//удалить ф-цию перед финальным коммитом
{
	int		i, j;

	i = 0;
	while (i < data->str)
	{
		j = 0;
		while (j < data->col)
		{
			printf("x = %d, y = %d, z = %d;	", data->map[i][j].x, \
			data->map[i][j].y, data->map[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	find_step(int str, int col)
{
	int	s1;
	int	s2;

	s1 = (1000 - 50) / (col);
	s2 = (600 - 50) / (str);
	if (s1 < s2)
		return (s1);
	else
		return (s2);
}

void	calculate_xy(t_data *data)
{
	int	step;
	int	i;
	int	j;

	step = find_step(data->str, data->col);
	printf("step = %d\n", step);
	i = data->str;
	while (--i + 1)//заполню координаты X и Y
	{
		j = data->col;
		while (--j + 1)
		{
			data->map[i][j].y = step * (i + 1) + 300\
			- (step * (data->str + 1) / 2);// 300 половина высоты окна
			data->map[i][j].x = step * (j + 1) + 500\
			- (step * (data->str + 1) / 2);// 500 половина ширины окна
		}
	}
}

void	write_z_to_map(t_map *map, char **points)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (points[i])
	{
		map[i].z = ft_atoi(points[i], &p);
		map[i].rgb = 16776960;// white color
		if (p)// в p лежит указатель на запятую в points
			map[i].rgb = 10005000;// написать программу для обработки цветов
			// но прежде надо разобраться как библиотека mlx принимает цвета
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
		//аллоцировал память под символы одной строки
		if (!data->map[i])
		{
			ft_free(points);
			ft_free_data(data);
			ft_errors(3);
		}
		write_z_to_map(data->map[i], points);
		ft_free(points);
		i++;//перешёл на следующую строку
	}
}

int	parser(char *av, t_data *data)
{
	int		fd;

	data->map = malloc(sizeof(t_map *) * data->str);
	//аллоцировал память под строки
	if (!data->map)
		ft_errors(3);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_errors(3);
	points_parser(fd, data);
	if (close(fd) == -1)
		ft_errors(3);
	calculate_xy(data);
	print_map(data);
	ft_free_data(data);
	return (0);
}
