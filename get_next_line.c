/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessiolongo <alessiolongo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:02:21 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/09 20:53:46 by alessiolong      ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len;

	len = ft_strlen(s);
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	res[len] = 0;
	while (len--)
		res[len] = s[len];
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int	i;

	//printf("%s\n", s1);
	//printf("%s\n", s2);
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
	
	i = 0;
	read(fd, buf, BUFFER_SIZE);
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		//printf("%d\n", buf[i]);
		i++;
	}
	//printf("%d\n", i);
	//printf("%s\n", buf);
	j = 0;
	if (i < BUFFER_SIZE)
	{
		//printf("%d\n", 1);
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
	{
		//printf("%s\n", buf);
		//printf("%d\n", 1);
		res = ft_strdup(buf);
		return (res);
	}
	//printf("%s\n", res);
	//printf("%d\n", 4);
	//printf("%s\n", res);
	printf("%s\n", buf);
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
	int			i = 4;

	tmp = NULL;
	res = NULL;
	signal = 1;
	res = read_buf(fd, buf);
	//printf("%s\n", res);
	while (signal || (buf[BUFFER_SIZE - 1] != '\0' && buf[BUFFER_SIZE - 1] != '\n'))
	//while (i--)
	{
		signal = 0;
		tmp = res;
		//printf("%s", read_buf(fd,buf));
		//printf("%s\n", res);
		res = ft_strjoin(res, read_buf(fd, buf));
		//printf("%s\n", res);
		if (res == NULL)
			return (NULL);
	}
	return (res);
}

int	main()
{
	char	*res;

	int	fd = open("./test.txt", O_RDONLY); // while be given as input of the function
	res = get_next_line(fd);
	printf("%s", res);

	return (0);
}
