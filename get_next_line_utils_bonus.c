/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessiolongo <alessiolongo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:17:33 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/16 11:45:59 by alessiolong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen( char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *) s)[i++] = 0;
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

void	*ft_memcpy(void *dst, const void *src, int n)
{
	const char	*s;
	char		*d;

	d = dst;
	s = src;
	if (!d && !s)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (&dst[0]);
}
