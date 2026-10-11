/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 20:24:38 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/11 19:22:39 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_all(void *content, int ischar)
{
	size_t	len;

	len = ft_strlen((char *) content);
	if (ischar)
	{
		len = 1;
		ft_putchar_fd(((char *) content)[0], 1);
	}
	else
		ft_putstr_fd((char *) content, 1);
	return (len);
}

static int	get_conv(t_list **lst, const char *str, size_t *i)
{
	char	*sub;
	size_t	offset;
	t_list	*node;

	if (str[0] != '%')
		return (1);
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

	if (str[0] == '%')
		return (1);
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
	if (!get_conv(&lst, &str[i], &i))
		return (clr_null(&lst));
	while (ft_strrchr(&str[i], '%'))
	{
		if (!get_token(&lst, &str[i], &i))
			return (clr_null(&lst));
		if (!get_conv(&lst, &str[i], &i))
			return (clr_null(&lst));
	}
	if (str[i])
	{
		if (!get_token(&lst, &str[i], &i))
			return (clr_null(&lst));
	}
	return (lst);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_list	*lst;
	int		bytes;

	va_start(args, str);
	lst = tokenize(str);
	if (!lst)
		return (-1);
	if (!va_lstiter(lst, selector, args))
		return (-1);
	bytes = print_iter(lst, print_all);
	va_end(args);
	ft_lstclear(&lst, free);
	return (bytes);
}
