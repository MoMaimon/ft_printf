/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 23:33:36 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/11 19:06:17 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_char(char *str, int arg, int *ischar)
{
	char	*str2;

	if (ft_strlen(str) != 2)
		return (NULL);
	if (str[ft_strlen(str) - 1] != 'c')
		return (print_int(str, arg));
	free(str);
	*ischar = 1;
	str2 = ft_calloc(2, sizeof(char));
	if (!str2)
		return (NULL);
	str2[0] = (char) arg;
	return (str2);
}
