/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:34:00 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/11 14:59:50 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ilen(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*str;
	long	temp;

	temp = n;
	len = ilen(temp);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (temp / 10)
	{
		str[len - 1] = (temp % 10) + '0';
		temp /= 10;
		len--;
	}
	str[len - 1] = (temp % 10) + '0';
	return (str);
}

char	*print_un(char *str, unsigned int arg)
{
	char	*str2;

	if (ft_strlen(str) != 2)
		return (NULL);
	free(str);
	str2 = ft_uitoa(arg);
	return (str2);
}
