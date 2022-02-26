/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:03:16 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/26 22:58:44 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	len_space(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	if (ft_isdigit(str[i]) || str[i] == ',' || str[i] == '-')
		space++;
	while (str[i])
	{
		if (str[i] == ' ' && ft_isdigit(str[i + 1]))
			space++;
		else if (str[i] == ' ' && str[i + 1] == ',')
			space++;
		else if (str[i] == ' ' && (str[i + 1] == '-' || str[i + 1] == '+'))
			space++;
		i++;
	}
	return (space);
}

int	check_strings(int fd, t_data *data)
{
	char	*line;
	int		len[3];

	line = get_next_line(fd);
	len[0] = len_space(line);
	len[1] = 0;// додумать логику парсера при чистой карте
	len[2] = 1;
	free(line);
	while (1)
	{
		data->col = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		len[1] = len_space(line);
		free(line);
		len[2]++;
		if (len[0] != len[1])
			return (1);
	}
	data->col = len[1];
	data->str = len[2];
	return (0);
}

int	validation_check(int argc, char **argv, t_data *data)
{
	int		fd;

	if (argc != 2)
		return (ft_errors(1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_errors(3);
	if (check_strings(fd, data))
		return (ft_errors(2));
	if (close(fd) == -1)
		ft_errors(3);
	return (0);
}
