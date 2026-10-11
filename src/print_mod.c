/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:44:04 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/11 14:59:07 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_mod(char *str)
{
	char	*str2;

	if (ft_strlen(str) != 2)
		return (NULL);
	free(str);
	str2 = ft_strdup("%");
	return (str2);
}
