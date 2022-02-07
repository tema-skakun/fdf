/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:31:34 by jg                #+#    #+#             */
/*   Updated: 2022/02/07 09:43:58 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int	check_strings(int fd)
// {
// 	char	*str;
// 	int		len[2];

// 	str = get_next_line(fd);
// 	len[0] = len_space(str);
// 	while (str)
// 	{
// 		str = get_next_line(fd);
// 		if (str == NULL)
// 			break ;
// 		len[1] = len_space(str);
// 		free(str);
// 		if (len[0] != len[1])
// 			return (1);
// 	}
// 	return (0);
// }

void	pre_parser(int fd, t_xyz *xyz)
{
	char	*str;
	char	**points;
	int		width;

	xyz->width = 0;
	xyz->height = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		points = ft_split(str, ' ');
		free(str);
		width = 0;
		while (points[width])
			width++;
		ft_free(points);
		xyz->width = width;
		printf("%d\n", width);
	}
}

int	parser(char *av, t_xyz *xyz)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_errors(3);
	pre_parser(fd, xyz);
	if (close(fd) == -1)
		ft_errors(3);
	// fd = open(av, O_RDONLY);
	// if (fd == -1)
	// 	ft_errors(3);
	// points_parser(fd);
	// if (close(fd) == -1)
	// 	ft_errors(3);
	return (0);
}
