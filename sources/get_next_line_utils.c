/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:28:25 by jg                #+#    #+#             */
/*   Updated: 2022/01/29 20:05:21 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// char	*ft_strchr(char *s, int c)
// {
// 	char	sym;

// 	sym = (char) c;
// 	while (*s != '\0')
// 	{
// 		s++;
// 		if (*s == sym)
// 			return ((char *)s);
// 	}
// 	return (NULL);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void			*mem;
// 	unsigned char	*ptr;
// 	int				i;

// 	mem = malloc(count * size);
// 	if (mem == NULL)
// 		return (NULL);
// 	i = size * count;
// 	ptr = (unsigned char *)mem;
// 	while (i--)
// 		*ptr++ = '\0';
// 	return (mem);
// }
