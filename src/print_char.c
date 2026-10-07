/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_char.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 23:33:36 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/07 23:57:50 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_char(char *str, int arg)
{
	char	*str2;

	if (!str)
		return (NULL);
	str2 = ft_calloc(2, sizeof(char));
	if (!str2)
		return (NULL);
	str2[0] = (char) arg;
	return (str2);
}
