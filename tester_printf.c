/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:57:28 by mlongo            #+#    #+#             */
/*   Updated: 2023/04/18 15:32:23 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int	main()
{
	char *p;

	p = "sono una stringa";
	ft_printf("il char e': %c e l'altro e' una stringa: %s\n", 'c', p);
	printf("il char e': %c e l'altro e' una stringa: %s mentre il suo indirizzo %p", 'c', p, p);
	return (0);
}
