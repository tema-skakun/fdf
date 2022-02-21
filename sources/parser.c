/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:31:34 by jg                #+#    #+#             */
/*   Updated: 2022/02/21 09:55:42 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_map(t_map **map, int *num)//удалить ф-цию перед финальным коммитом
{
	int		i, j;

	i = 0;
	while (i < num[0])
	{
		j = 0;
		while (j < num[1])
		{
			printf("%d,%d ", map[i][j].z, map[i][j].rgb);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	map_write(t_map *map, char **points)
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

void	points_parser(int fd, t_map **map, int *num)
{
	int		i;
	char	*str;
	char	**points;

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		points = ft_split(str, ' ');
		free(str);
		map[i] = malloc(sizeof(t_map) * num[1]);
		//аллоцировал память под символы одной строки
		if (!map[i])
		{
			ft_free(points);
			ft_free_map(map, num);
			ft_errors(3);
		}
		map_write(map[i], points);
		ft_free(points);
		i++;//перешёл на следующую строку
	}
}

void	pre_alloc(int fd, int *num)
{
	char	*str;

	str = get_next_line(fd);
	num[1] = len_space(str);
	free(str);
	num[0] = 1;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		num[0]++;
		free(str);
	}
}

int	parser(char *av, int *num)
{
	int		fd;
	t_map	**map;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_errors(3);
	pre_alloc(fd, num);
	//посчитал кол-во символов в строке и кол-во строк
	if (close(fd) == -1)
		ft_errors(3);
	printf("num[0] = %d\nnum[1] = %d\n", num[0], num[1]);
	map = malloc(sizeof(t_map *) * num[0]);
	//аллоцировал память под строки
	if (!map)
		ft_errors(3);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_errors(3);
	points_parser(fd, map, num);
	if (close(fd) == -1)
		ft_errors(3);
	print_map(map, num);
	ft_free_map(map, num);
	return (0);
}
