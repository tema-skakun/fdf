/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:56:03 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/01/29 20:06:00 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"

int		parser(int argc, char **argv);
int		ft_errors(int i);

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strcpy(char *dest, char *src);

#endif
