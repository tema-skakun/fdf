/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:03:16 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/01/29 20:07:34 by fdarkhaw         ###   ########.fr       */
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

int	parser(int argc, char **argv)
{
	char	*str;

	str = argv[0];
	if (argc != 2)
		return (ft_errors(1));
	return (0);
}
