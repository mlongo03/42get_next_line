/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessiolongo <alessiolongo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:02:21 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/15 17:14:54 by alessiolong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*expand_res(char *current)
{
	char	*res;

	if (!current)
	{
		res = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		return (res);
	}
	res = (char *)ft_calloc(sizeof(char), (ft_strlen(current) + BUFFER_SIZE) + 1);
	ft_memcpy(res, current, ft_strlen(current));
	free(current);
	return (res);
}

void	load_res(char *res, char *buf)
{
	int i;

	i = 0;
	if (!res[0] && !buf[0])
		return ;
	while(*res)
		res++;
	while (buf[i])
	{
		res[i] = buf[i];
		if (res[i++] == '\n')
		{
			ft_memcpy(buf, &res[i], ft_strlen(res) - i);
			ft_memset(buf, 0, BUFFER_SIZE - (ft_strlen(res) - i));
		}
	}
}

char	*get_next_line(int fd)
{
	char static buf[BUFFER_SIZE];
	char 		*res;
	int			countread;

	if (fd < 0 || fd >= 4096 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	res = expand_res(NULL);
	load_res(res, buf);
	countread = read(fd, buf, BUFFER_SIZE);
	while (countread > 0 && res[ft_strlen(res) - 1] != '\n')
	{
		res = expand_res(res);
		load_res(res, buf);
		countread = read(fd, buf, BUFFER_SIZE);
	}
	if (countread < 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
