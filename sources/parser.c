/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:31:34 by jg                #+#    #+#             */
/*   Updated: 2022/02/23 14:21:02 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	find_chr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return (i);
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

static size_t	ft_strlen_base(const char *str, int *f)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 102)
			*f = 1;
		i++;
	}
	return (i);
}

unsigned int	ft_atoh(const char *str)
{
	int				i;
	int				a;
	int				len;
	unsigned int	res;
	char			*base;

	i = 0;
	res = 0;
	a = 0;
	base = "0123456789ABCDEF";
	len = ft_strlen_base(&str[i], &a);
	if (a)
		base = "0123456789abcdef";
	a = find_chr(base, str[i]);
	if (a != -1)
	{
		while (len--)
		{
			a = find_chr(base, str[i++]);
			res += pow(16, len) * a;
		}
	}
	return (res);
}

// unsigned int	ft_atoh(const char *str)
// {
// 	a
// }

void	print_map(t_data *data)//удалить ф-цию перед финальным коммитом
{
	int		i, j;

	i = 0;
	while (i < data->str)
	{
		j = 0;
		while (j < data->col)
		{
			printf("x %d, y %d, rgb %d;	", data->map[i][j].x, \
			data->map[i][j].y, data->map[i][j].rgb);
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

	s1 = (1000 - 20) / (col);
	s2 = (600 - 20) / (str);
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
	// printf("step = %d\n", step);
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
	while (points[i])
	{
		p = 0;
		map[i].z = ft_atoi(points[i], &p);
		map[i].rgb = 0x00FFFFFF;// white color
		if (p)// в p лежит указатель на запятую в points
			map[i].rgb = ft_atoh(points[i] + p + 3);
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
	return (0);
}
