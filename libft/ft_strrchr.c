/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strrchr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/23 14:37:51 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/09/26 17:40:17 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (c >= 256)
		c -= 256;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *) & (s[i]));
		i--;
	}
	return (0);
}
