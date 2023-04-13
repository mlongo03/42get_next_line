/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:02:21 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/13 19:28:52 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *) s)[i++] = 0;
}

char	*ft_strjoin(char *s1, char *s2)
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
	free(s1);
	free(s2);
	return (res);
}

void	*ft_calloc(int count, int size)
{
	void	*res;
	int		len;

	len = count * size;
	res = (void *) malloc(len);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, len);
	return (res);
}

char	*get_res(char *buf, int end)
{
	char	*res;
	int		index;

	ft_strchr(buf, '\n', &index);
	if (end == BUFFER_SIZE)
	{
		res = ft_substr(buf, 0, index);
		ft_strcpy(&buf, &buf, index, BUFFER_SIZE - index);
	}
	else
	{
		if (index >= end)
		{
			res = ft_substr(buf, 0, end);
			ft_bzero(buf, BUFFER_SIZE);
		}
		else
		{
			res = ft_substr(buf, 0, index);
			ft_strcpy(&buf, &buf, index, BUFFER_SIZE - index);
		}
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char static	buf[BUFFER_SIZE];
	char		*res;
	char		*ptr;
	char		*tmp;
	int			end;
	int			i;

	if (fd < 0 || fd >= 4096 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	res = ft_calloc(1, 1);
	if (!res)
		return (NULL);
	tmp = res;
	end = 0;
	ptr = buf;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (ptr[0])
	{
		res = get_res(ptr, ft_strlen(ptr));
		free(tmp);
	}
	if (ft_strchr(res, '\n', &i) >= 0)
		return (res);
	end = read(fd, ptr, BUFFER_SIZE);
	while (end)
	{
		if (end == 0)
			return (NULL);
		if (end == (-1))
		{
			free(buf);
			return (NULL);
		}
		res = ft_strjoin(res, get_res(ptr, end));
		if (ft_strchr(res, '\n', &i) >= 0)
			break ;
		end = read(fd, ptr, BUFFER_SIZE);
	}
	return (res);
}
