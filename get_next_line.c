/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:02:21 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/14 18:53:07 by mlongo           ###   ########.fr       */
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	d = dst;
	s = src;
	if (!d && !s)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*expand_res(char *current, char *buf)
{
	char	*res;

	if (!current)
	{
		res = (char *)ft_calloc(BUFFER_SIZE + 1);
		return (res);
	}
	res = (char *)ft_calloc(((ft_strlen(current)) + BUFFER_SIZE) + 1);
	res = ft_memcpy(res, current, ft_strlen(current));
	free(current);
	return (res);
}

char	*load_res(buf)
{

}

char	*get_next_line(int fd)
{
	char static res[BUFFER_SIZE];
	char 		*res;
	int			countread;

	if (fd < 0 || fd >= 4096 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	res = expand_res(NULL, buf);
	res = load_res(res, buf);
	countread = read(fd, buf, BUFFER_SIZE);
	while (countread && res[ft_strlen(res) - 1] != '\n')
	{
		res = expand_res(res, buf);
		res = load_res(buf);
		countread = read(fd, buf, BUFFER_SIZE);
	}
	return (res);
}
