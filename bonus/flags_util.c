/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   flags_util.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/12 18:40:15 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/13 17:15:19 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

char	*get_flags(char *str)
{
	size_t	len;
	char	*flags;

	len = ft_strlen(str);
	if (len == 2)
		return (NULL);
	flags = malloc(len - 1);
	if (!flags)
		return (NULL);
	ft_strlcpy(flags, &str[1], len - 1);
	return (flags);
}

int	get_width(char *flags)
{
	size_t	i;
	size_t	dot;
	char	*width;
	int		iwidth;

	i = ft_strindx(flags, "0123456789");
	dot = ft_strindx(flags, ".");
	if (!i)
		return (-1);
	if (dot && dot < i)
		return (0);
	width = ft_substr(flags, i, dot - i);
	if (!width)
		return (0);
	iwidth = ft_atoi(width);
	free(width);
	return (iwidth);
}
