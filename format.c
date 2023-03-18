/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 06:10:17 by malancar          #+#    #+#             */
/*   Updated: 2023/03/18 06:11:49 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int				len;
	long long int	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
		len++;
	}
	if (nb >= 10)
		len = len + ft_putnbr(nb / 10);
	len = len + ft_putchar((nb % 10) + 48);
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len = len + ft_putunbr(n / 10);
	len = len + ft_putchar((n % 10) + 48);
	return (len);
}

int	ft_puthex(unsigned long int n, char c)
{
	int		len;

	len = 0;
	if (n >= 16)
		len = len + ft_puthex((n / 16), c);
	if (n % 16 < 10)
		len = len + ft_putchar((n % 16) + 48);
	else
	{
		if (c == 'X')
			len = len + ft_putchar((n % 16) + 'A' - 10);
		else
			len = len + ft_putchar((n % 16) + 'a' - 10);
	}
	return (len);
}
