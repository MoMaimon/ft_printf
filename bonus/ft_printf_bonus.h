/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_bonus.h                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/29 20:25:00 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/13 17:16:04 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putadd(void *ptr);
int		selector(void **content, va_list args, int *ischar);
int va_lstiter(t_list * lst, int(*f)(void * *, va_list, int *),
	va_list	args);
int		print_iter(t_list *lst, int (*f)(void *, int));
void	*clr_null(t_list **lst);
char	*print_char(char *str, int arg, int *ischar);
char	*print_str(char *str, char *arg);
char	*print_ptr(char *str, void *arg);
char	*print_int(char *str, int arg);
char	*print_un(char *str, unsigned int arg);
char	*print_hex(char *str, unsigned int arg, char x);
char	*print_mod(char *str);
char	*ft_dtox(unsigned long dec, char *digits);
int		max(int num1, int num2);
char	*get_flags(char *str);
int		get_width(char *flags);

#endif
