/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_tester.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:08:34 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/12 11:09:05 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd = open("./test.txt", 0);
	char *res = get_next_line(fd);
	int	 i;
	printf("%s", res);
	while (res && *res)
	{
		res = get_next_line(fd);
		if (res)
			printf("%s", res);
	}
	return 0;
}
