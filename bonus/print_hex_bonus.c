/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:40:58 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/12 15:29:48 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*print_hex(char *str, unsigned int arg, char x)
{
	char	*digits;
	char	*str2;

	if (ft_strlen(str) != 2)
		return (NULL);
	free(str);
	if (x == 'x')
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	str2 = ft_dtox(arg, digits);
	return (str2);
}
