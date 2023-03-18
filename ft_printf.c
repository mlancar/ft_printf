/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:55:12 by malancar          #+#    #+#             */
/*   Updated: 2023/03/18 06:13:19 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && check_letter(format[i + 1]))
		{
			len = len + check_format(args, format[i + 1]);
			i++;
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*#include <stdio.h>
#include <limits.h>
int	main()
{
	char c = 'z';
	char s[] = "sauce tomate";
	int i = -1;
	int d = -1;
	unsigned int u = -1;
	int p = -1;

	

	printf("%d\n", ft_printf("%x\n", 9223372036854775807LL));
	printf("%d\n", printf("%x\n", 9223372036854775807LL));
}*/
