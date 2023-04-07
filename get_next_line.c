/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:02:21 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/07 19:22:39 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// int	BUFFER_SIZE = 10; // -D BUFFER_SIZE=n

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int	i;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	res[ft_strlen(s1) + ft_strlen(s2)] = 0;
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		res[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	return (res);
}

char	*read_buf(int fd, char *buf)
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

char	*get_next_line(int fd)
{
	// tester variables

	char static	buf[BUFFER_SIZE];
	char		*tmp;
	char		*res;
	int			signal;

	tmp = NULL;
	res = NULL;
	signal = 1;
	res = read_buf(fd, buf);
	while (signal || (buf[BUFFER_SIZE - 1] != '\0' && buf[BUFFER_SIZE - 1] != '\n'))
	{
		signal = 0;
		tmp = res;
		//printf("%s", read_buf(fd,buf));
		res = ft_strjoin(res, read_buf(fd, buf));
		//printf("%s", res);
		if (res == NULL)
			return (NULL);
		if (tmp)
			free(tmp);
	}
	return (res);
}

int	main()
{
	char	*res;

	int	fd = open("./test.txt", O_RDONLY); // while be given as input of the function
	res = get_next_line(fd);
	//printf("%s", res);

	return (0);
}
