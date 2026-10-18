/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 23:33:36 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/13 20:39:17 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*handle_flag(char *flags, int arg, char *set)
{
	int	width;
	int	option;

	option = 1;
	if (!set)
		return (NULL);
	while ()
	}

char	*make_set(char *alwd_flgs)
{
	int		i;
	char	*set;

	i = 0;
	set = ft_calloc(255, sizeof(char));
	if (!set)
		return (NULL);
	while (alwd_flgs[i])
		set[(unsigned char) alwd_flgs[i++]] = 1;
	i = 0;
	while (i < 10)
		set[i] = 2;
	return (set);
}

char	*print_char(char *str, int arg, int *ischar)
{
	char	*str2;
	char	*flags;

	if (ft_strlen(str) != 2)
		return (NULL);
	if (str[ft_strlen(str) - 1] != 'c')
		return (print_int(str, arg));
	if (!arg)
		*ischar = 1;
	flags = get_flags(str);
	free(str);
	if (flags)
		return (handle_flag(flags, arg, make_set("-")));
	str2 = ft_calloc(2, sizeof(char));
	if (!str2)
		return (NULL);
	str2[0] = (char) arg;
	return (str2);
}
