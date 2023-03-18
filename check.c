/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 06:09:39 by malancar          #+#    #+#             */
/*   Updated: 2023/03/18 06:16:27 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_letter(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "cspdiuxX%";
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_format(va_list args, char c)
{
	int					len;
	unsigned long long	p;

	p = 0;
	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		len = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len = ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
	{
		p = va_arg(args, unsigned long);
		if (p == 0)
			return (ft_putstr("(nil)"));
		len = ft_putstr("0x") + ft_puthex(p, c);
	}
	else if (c == '%')
		len = ft_putchar(c);
	return (len);
}
