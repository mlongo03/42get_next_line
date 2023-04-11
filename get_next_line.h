/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:41:27 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/11 16:48:01 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
void	ft_strcpy(char **dst, char **src, int start, int size);
int		ft_strchr(char *s, int c);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*read_buf(int fd, char *buf);

#endif
