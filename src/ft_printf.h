/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/29 20:25:00 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/07 23:52:43 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *, ...);
void	ft_putadd(void *ptr);
int		selector(void **content, va_list args);
int		va_lstiter(t_list *lst, int (*f)(void * *, va_list), va_list args);
char	*print_char(char *str, int arg);
char	*print_str(char *str, char *arg);
char	*print_ptr(char *str, void *arg);
char	*print_int(char *str, int arg);
char	*print_un(char *str, unsigned int arg);
char	*print_hex(char *str, unsigned int arg);
char	*print_mod(char *str);

#endif
