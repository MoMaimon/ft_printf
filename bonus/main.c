/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 21:04:48 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/12 15:29:44 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	char	*str = "";
	int ret1, ret2;
	// printf("%s | %s\n", str[2], str[1]);
	ret1 = printf(" %%%% \n");
	ret2 = ft_printf(" %%%% \n");
	printf("ret1: %i | ret2: %i", ret1, ret2);
}

// int main(void)
// {
// 	int ret1, ret2;
// 	ret1 = ft_printf("ft: NULL test: %rp\n", 0);
// 	ret2 = printf("og: NULL test: %rp\n", 0);
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	// Characters
// 	ret1 = ft_printf("ft: Char test: %c\n", 'A');
// 	ret2 = printf("og: Char test: %c\n", 'A');
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	// Strings
// 	ret1 = ft_printf("ft: String test: %s\n", "Hello, world!");
// 	ret2 = printf("og: String test: %s\n", "Hello, world!");
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	// Null string
// 	ret1 = ft_printf("ft: Null string: %s\n", (char *)NULL);
// 	ret2 = printf("og: Null string: %s\n", (char *)NULL);
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	// Integers
// 	ret1 = ft_printf("ft: Integer test: %d\n", -12345);
// 	ret2 = printf("og: Integer test: %d\n", -12345);
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	// Unsigned integers
// 	ret1 = ft_printf("ft: Unsigned test: %u\n", 12345u);
// 	ret2 = printf("og: Unsigned test: %u\n", 12345u);
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	// Hex lowercase
// 	ret1 = ft_printf("ft: Hex lowercase: %x\n", 305441741);
// 	ret2 = printf("og: Hex lowercase: %x\n", 305441741);
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	// Hex uppercase
// 	ret1 = ft_printf("ft: Hex uppercase: %X\n", 305441741);
// 	ret2 = printf("og: Hex uppercase: %X\n", 305441741);
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	// Pointer
// 	int x = 42;
// 	ret1 = ft_printf("ft: Pointer test: %p\n", &x);
// 	ret2 = printf("og: Pointer test: %p\n", &x);
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	// Percent sign
// 	ret1 = ft_printf("ft: Percent test: %%\n");
// 	ret2 = printf("og: Percent test: %%\n");
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	// Edge cases: INT_MAX, INT_MIN, UINT_MAX
// 	ret1 = ft_printf("ft: INT_MAX: %d | INT_MIN: %d | UINT_MAX: %u\n", 2147483647, -2147483648, 4294967295u);
// 	ret2 = printf("og: INT_MAX: %d | INT_MIN: %d | UINT_MAX: %u\n", 2147483647, -2147483648, 4294967295u);
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	// Continuous output without newlines
// 	ret1 = ft_printf("ft:START-%c-%s-%p-%d-%u-%x-%X-%%-END\n",
// 	'B', "NoNewline", (void*)0x42, -2025, 2025, 0xBEEF, 0xBEEF);
// 	ret2 = printf("og:START-%c-%s-%p-%d-%u-%x-%X-%%-END\n",
// 	'B', "NoNewline", (void*)0x42, -2025, 2025, 0xBEEF, 0xBEEF);
// 	printf("ret(ft) = %d | ret(og) = %d\n\n", ret1, ret2);
// 	return 0;
// }