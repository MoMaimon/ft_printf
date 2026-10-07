/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/29 20:24:38 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/07 22:13:54 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	g_bytes;

static void	print_all(void *content)
{
	static int	i;

	g_bytes += ft_strlen((char *) content);
	ft_putstr_fd("[Node:  ", 1);
	ft_putnbr_fd(i++, 1);
	ft_putstr_fd("] ", 1);
	ft_putendl_fd((char *) content, 1);
}

static int	get_conv(t_list **lst, const char *str, size_t *i)
{
	char	*sub;
	size_t	offset;
	t_list	*node;

	offset = ft_strindx(&str[1], "cspdiuxX%");
	if (!offset)
		return (0);
	sub = ft_substr(str, 0, offset + 1);
	if (!sub)
		return (0);
	node = ft_lstnew(sub);
	if (!node)
		return (0);
	ft_lstadd_back(lst, node);
	*i += offset + 1;
	return (1);
}

static int	get_token(t_list **lst, const char *str, size_t *i)
{
	char	*sub;
	size_t	offset;
	t_list	*node;

	offset = ft_strindx(str, "%");
	if (!offset)
		offset = ft_strlen(str) + 1;
	sub = ft_substr(str, 0, offset - 1);
	if (!sub)
		return (0);
	node = ft_lstnew(sub);
	if (!node)
		return (0);
	ft_lstadd_back(lst, node);
	*i += offset - 1;
	return (1);
}

static t_list	*tokenize(const char *str)
{
	size_t	i;
	t_list	*lst;

	lst = NULL;
	i = 0;
	if (!ft_strindx(str, "%"))
		return (ft_lstnew((void *) ft_strdup(str)));
	while (ft_strrchr(&str[i], '%'))
	{
		if (!get_token(&lst, &str[i], &i))
			return (NULL);
		if (!get_conv(&lst, &str[i], &i))
			return (NULL);
	}
	if (str[i])
	{
		if (!get_token(&lst, &str[i], &i))
			return (NULL);
	}
	return (lst);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_list	*lst;

	va_start(args, str);
	lst = tokenize(str);
	if (!lst)
	{
		ft_lstclear(&lst, free);
		return (-1);
	}
	ft_lstiter(lst, print_all);
	va_end(args);
	ft_lstclear(&lst, free);
	return (g_bytes);
}
