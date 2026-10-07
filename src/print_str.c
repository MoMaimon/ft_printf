/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_str.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 23:34:39 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/07 23:56:54 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_str(char *str, char *arg)
{
	char	*str2;

	str2 = ft_strdup(arg);
	free(str);
	return (str2);
}
