/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtox_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:13:05 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/12 15:29:38 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	xlen(unsigned long n)
{
	long	len;

	len = 1;
	while (n / 16)
	{
		len++;
		n /= 16;
	}
	return (len);
}

char	*ft_dtox(unsigned long dec, char *digits)
{
	char	*hex;
	int		len;

	len = xlen(dec);
	hex = ft_calloc(len + 1, sizeof(char));
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	while (dec / 16)
	{
		hex[--len] = digits[dec % 16];
		dec = dec / 16;
	}
	hex[--len] = digits[dec % 16];
	return (hex);
}
