/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:17:33 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/11 16:10:41 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	int	i;
	int	j;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		str = ft_strdup("");
	else if (len < ft_strlen(s) - start)
		str = (char *) malloc(sizeof(*s) * (len + 1));
	else
		str = (char *) malloc(sizeof(*s) * (ft_strlen(s) - start));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

void	ft_strcpy(char **dst, char *src, int start, int size)
{
	int		j;

	j = 0;
	while (j < BUFFER_SIZE)
	{
		if (j < size)
			(*dst)[j] = src[start++];
		else
			(*dst)[j] = 0;
		j++;
	}
}

int	ft_strchr( char *s, int c)
{
	char	*r;
	char	x;
	int		i;

	x = (char) c;
	r = (char *) s;
	i = 0;
	while (r[i] && r[i] != x)
		i++;
	return (i);
}

int	ft_strlen( char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup( char *s)
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
