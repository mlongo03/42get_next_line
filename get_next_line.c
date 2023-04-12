/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:02:21 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/12 19:28:54 by mlongo           ###   ########.fr       */
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
	return (res);
}

void	ft_check_read2(char **buf, char **res)
{
	char	*tmp;
	int	i;

	i = ft_strchr(*buf, '\n') + 1;
	if (i < BUFFER_SIZE)
	{
		tmp = *res;
		*res = ft_substr(*buf, 0, i);
		free(tmp);
		ft_strcpy(buf, buf, i, BUFFER_SIZE - i);
	}
	else
	{
		// tmp = *res;
		*res = ft_strdup(*buf);
		// free(tmp);
	}
}

void	ft_check_read(char **buf, char **res)
{
	char	*tmp;
	int		i;

	i = ft_strchr(*buf, '\n') + 1;
	if (i < BUFFER_SIZE)
	{
		tmp = *res;
		*res = ft_substr(*buf, 0, i);
		free(tmp);
		ft_strcpy(buf, buf, i, BUFFER_SIZE - i);
	}
	else
	{
		// tmp = *res;
		*res = ft_strdup(*buf);
		// free(tmp);
		ft_bzero(*buf, i);
	}
}

char	*read_buf(int fd, char *buf)
{
	char	*res;
	int		i;

	i = read(fd, buf, BUFFER_SIZE);
	if (!i)
		return (NULL);
	if (i < BUFFER_SIZE)
	{
		res = ft_substr(buf, 0, i);
		ft_strcpy(&buf, &res, 0, i);
	}
	ft_check_read2(&buf, &res);
	return (res);
}

char	*get_next_line(int fd)
{
	char static	buf[BUFFER_SIZE];
	char		*tmp;
	char		*res;
	char		*ptr;

	ptr = buf;
	tmp = NULL;
	res = NULL;
	if (buf[0])
		ft_check_read(&ptr, &res);
	else
		res = read_buf(fd, buf);
	if (!res)
		return (NULL);
	while (buf[BUFFER_SIZE - 1] != '\0' && buf[BUFFER_SIZE - 1] != '\n')
	{
		tmp = res;
		res = ft_strjoin(res, read_buf(fd, buf));
		if (!res)
			return (NULL);
		free(tmp);
	}
	return (res);
}
