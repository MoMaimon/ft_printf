/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 23:34:39 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/12 15:29:57 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*print_str(char *str, char *arg)
{
	char	*str2;

	if (ft_strlen(str) != 2)
		return (NULL);
	free(str);
	if (!arg)
		return (ft_strdup("(null)"));
	str2 = ft_strdup(arg);
	return (str2);
}
