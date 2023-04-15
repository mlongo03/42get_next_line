/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessiolongo <alessiolongo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:41:27 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/15 18:41:44 by alessiolong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_calloc(int count, int size);
char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
void	ft_strcpy(char **dst, char **src, int start, int size);
int		ft_strchr(char *s, int c);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*read_buf(int fd, char *buf);
void	*ft_memset(char *s, int c, int n);

#endif
