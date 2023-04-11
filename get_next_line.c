/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:02:21 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/11 19:10:41 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*ft_strjoin(char  *s1, char  *s2)
{
	char	*res;
	int		i;

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

	if(!read(fd, buf, BUFFER_SIZE))
		return (NULL);
	i = ft_strchr(buf, '\n') + 1;
	if (i < BUFFER_SIZE)
	{
		res	= ft_substr(buf, 0, i);
		ft_strcpy(&buf, &buf, i, BUFFER_SIZE - i);
	}
	else
		res = ft_strdup(buf);
	return (res);
}

char	*get_next_line(int fd)
{
	char static	buf[BUFFER_SIZE];
	char		*tmp;
	char		*res;
	int			i;
	char		*ptr;

	ptr = buf;
	tmp = NULL;
	res = NULL;
	if (buf[0])
	{
		i = ft_strchr(buf, '\n') + 1;
		if (i < BUFFER_SIZE)
		{
			res	= ft_substr(buf, 0, i);
			ft_strcpy(&ptr, &ptr, i, BUFFER_SIZE - i);
		}
		else
			res = ft_strdup(buf);
	}
	else
		res = read_buf(fd, buf);
	if (!res)
		return (NULL);
	while (buf[BUFFER_SIZE - 1] != '\0' && buf[BUFFER_SIZE - 1] != '\n')
	{
		res = ft_strjoin(res, read_buf(fd, buf));
		if (!res)
			return (NULL);
	}
	return (res);
}
