/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:22:29 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/11 14:59:00 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_int(char *str, int arg)
{
	char	*str2;

	if (ft_strlen(str) != 2)
		return (NULL);
	free(str);
	str2 = ft_itoa(arg);
	return (str2);
}
