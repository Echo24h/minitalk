/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:17:20 by gborne            #+#    #+#             */
/*   Updated: 2022/01/12 01:30:26 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_printf(char c, int size)
{
	write(1, &c, 1);
	size++;
	return (size);
}

int	ft_putstr_printf(char *s, int size)
{
	if (s)
		while (*s)
			size = ft_putchar_printf(*s++, size);
	else
		size = ft_putstr_printf("(null)", size);
	return (size);
}

int	ft_putnbr_printf(int n, int size)
{
	if (n == -2147483648)
		size = ft_putstr_printf("-2147483648", size);
	else
	{
		if (n < 0)
		{
			n *= -1;
			size = ft_putchar_printf('-', size);
		}
		if (n > 9)
		{
			size = ft_putnbr_printf(n / 10, size);
			size = ft_putnbr_printf(n % 10, size);
		}
		else
			size = ft_putchar_printf(n + 48, size);
	}
	return (size);
}

int	ft_putunbr_printf(unsigned int n, int size)
{
	if (n > 9)
	{
		size = ft_putunbr_printf(n / 10, size);
		size = ft_putunbr_printf(n % 10, size);
	}
	else
		size = ft_putchar_printf(n + 48, size);
	return (size);
}

int	ft_puthexa_printf(unsigned long n, char *base, int size)
{
	if (n >= 16)
		size = ft_puthexa_printf(n / 16, base, size);
	size = ft_putchar_printf(base[n % 16], size);
	return (size);
}
