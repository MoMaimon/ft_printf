/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_ptr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/10 17:03:15 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/11 20:17:03 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_ptr(char *str, void *arg)
{
	unsigned long	dec;
	char			*hex;
	char			*ptr;

	if (ft_strlen(str) != 2)
		return (NULL);
	free(str);
	dec = (unsigned long) arg;
	if (!dec)
		return (ft_strdup("(nil)"));
	hex = ft_dtox(dec, "0123456789abcdef");
	if (!hex)
		return (NULL);
	ptr = ft_strjoin("0x", hex);
	free(hex);
	if (!ptr)
		return (NULL);
	return (ptr);
}
