/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:03:16 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/10 13:02:27 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	ft_free(char **p_str)
// {
// 	int	i;

// 	i = 0;
// 	if (p_str != NULL)
// 	{
// 		while (p_str[i])
// 			free(p_str[i++]);
// 		free(p_str);
// 	}
// }

// int	ft_getnbr(char *str)
// {
// 	size_t	i;
// 	int		result;

// 	result = 0;
// 	i = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 		i++;
// 	while ((str[i] >= '0') && (str[i] <= '9'))
// 	{
// 		result = (result * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	if (str[0] == '-')
// 		result = result * (-1);
// 	return (result);
// }

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

int	check_strings(int fd)
{
	char	*str;
	int		len[2];

	str = get_next_line(fd);
	len[0] = len_space(str);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		len[1] = len_space(str);
		free(str);
		if (len[0] != len[1])
			return (1);
	}
	return (0);
}

int	validation_check(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_errors(1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_errors(3);
	if (check_strings(fd))
		return (ft_errors(2));
	if (close(fd) == -1)
		ft_errors(3);
	return (0);
}
