/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jg <jg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:03:16 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/02 12:49:21 by jg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int	ft_getnbr(char *str)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		result = result * (-1);
	return (result);
}

int	len_space(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (str[i])
	{
		// if (str[i] == 32 && str[i + 1] != 32)
		// 	space++;
		if (str[i] == 32 && ft_isdigit(str[i + 1]))
			space++;
		//перенос каретки или конец строки после пробела не всчёт
		// if (str[i] == 32 && str[i + 1] == '\n')
		// 	space--;
		// if (str[i] == 32 && str[i + 1] == '\0')
		// 	space--;
		i++;
	}
	return (space);
}

int	check_strings(int fd)
{
	char	*str;
	int		first;
	int		next;

	str = get_next_line(fd);
	first = len_space(str);
	printf("first = %d\n", first);
	printf("%s", str);
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		next = len_space(str);
		printf("next = %d\n", next);
		printf("%s", str);
		free(str);
		if (first != next)
			return (1);
	}
	printf("\nok\n");
	return (0);
}

int	parser(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_errors(1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_errors(4);
	if (check_strings(fd))
		return (ft_errors(2));
	return (0);
}
