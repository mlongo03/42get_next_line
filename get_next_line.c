/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:02:21 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/07 13:33:10 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	BUFFER_SIZE = 10; // -D BUFFER_SIZE=n

char	*read_buf(int fd, char static *buf)
{
	char	*res;
	int		i;
	int		j;

	read(fd, buf, BUFFER_SIZE);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	i++;
	j = 0;
	if (i < BUFFER_SIZE)
	{
		res = (char *) malloc(i + 1);
		if (res == NULL)
			return (NULL);
		res[i] = 0;
		while (j < i)
		{
			res[j] = buf[j];
			j++;
		}
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (i < (BUFFER_SIZE - (BUFFER_SIZE - j - 2)))
			{
				buf[i] = res[BUFFER_SIZE - j - 2 + i];
				res[BUFFER_SIZE - j - 2 + i] = 0;
			}
			else
				buf[i] = 0;
			i++;
		}
	}
	else
		return (buf);
	return (res);
}
	// buffer size < \n (deve tornare la new line lo stesso...)
	// buffer size > \n (static char *extra_chars)

int	get_next_line()
{
	// tester variables
	int	fd = open("./test.txt", O_RDONLY); // while be given as input of the function

	char static	buf[BUFFER_SIZE];
	char		*tmp;
	char		*res;
	int			signal;

	tmp = NULL;
	res = NULL;
	signal = 1;
	while (signal || buf[BUFFER_SIZE] != '\0' && buf[BUFFER_SIZE] != '\n')
	{
		signal = 0;
		tmp = res;
		res = ft_strjoin(res, read_buf(fd, buf));
		if (res == NULL)
			return (NULL);
		if (tmp)
			free(tmp);
	}
	return (res);
}
