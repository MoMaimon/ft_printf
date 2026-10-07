/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   selector.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 22:15:36 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/07 23:54:19 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	selector(void **content, va_list args)
{
	size_t	len;
	char	*str;

	str = *content;
	if (!str)
		return (0);
	len = ft_strlen(str) - 1;
	if (str[0] != '%')
		return (1);
	if (str[len] == 'c')
		*content = print_char(str, va_arg(args, int));
	else if (str[len] == 's')
		*content = print_str(str, va_arg(args, char *));
	// else if (str[len] == 'p')
	// 	*content = print_ptr(str, va_arg(args, void *));
	// else if (str[len] == 'd' || str[len] == 'i')
	// 	*content = print_int(str, va_arg(args, int));
	// else if (str[len] == 'u')
	// 	*content = print_un(str, va_arg(args, unsigned int));
	// else if (str[len] == 'x' || str[len] == 'X')
	// 	*content = print_hex(str, va_arg(args, unsigned int));
	// // i can merge un with hex to save lines.
	// else if (str[len] == '%')
	// 	*content = print_mod(str);
	if (!*content)
		return (0);
	return (1);
}

int	va_lstiter(t_list *lst, int (*f)(void * *, va_list), va_list args)
{
	if (!f)
		return (0);
	while (lst)
	{
		if (!f(&(lst->content), args))
			return (0);
		lst = lst->next;
	}
	return (1);
}
