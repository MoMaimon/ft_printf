/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:15:36 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/11 20:18:32 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	selector(void **content, va_list args, int *ischar)
{
	size_t	len;
	char	*str;

	str = *content;
	if (!str)
		return (0);
	len = ft_strlen(str) - 1;
	if (str[0] != '%')
		return (1);
	if (str[len] == 'c' || str[len] == 'i' || str[len] == 'd')
		*content = print_char(str, va_arg(args, int), ischar);
	else if (str[len] == 's')
		*content = print_str(str, va_arg(args, char *));
	else if (str[len] == 'p')
		*content = print_ptr(str, va_arg(args, void *));
	else if (str[len] == 'u')
		*content = print_un(str, va_arg(args, unsigned int));
	else if (str[len] == 'x' || str[len] == 'X')
		*content = print_hex(str, va_arg(args, unsigned int), str[len]);
	else if (str[len] == '%')
		*content = print_mod(str);
	if (!*content)
		return (0);
	return (1);
}

int	print_iter(t_list *lst, int (*f)(void *, int))
{
	int	bytes;

	if (!f)
		return (-1);
	bytes = 0;
	while (lst)
	{
		bytes += f(lst->content, lst->ischar);
		lst = lst->next;
	}
	return (bytes);
}

void	*clr_null(t_list **lst)
{
	if (*lst)
		ft_lstclear(lst, free);
	return (NULL);
}

int	va_lstiter(t_list *lst, int (*f)(void **, va_list, int *), va_list args)
{
	if (!f)
		return (0);
	while (lst)
	{
		if (!f(&(lst->content), args, &(lst->ischar)))
			return (0);
		lst = lst->next;
	}
	return (1);
}
