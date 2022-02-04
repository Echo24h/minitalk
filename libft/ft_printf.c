/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:17:20 by gborne            #+#    #+#             */
/*   Updated: 2022/01/12 01:35:30 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sort_printf(va_list *arg, char type, int size)
{
	if (type == 'c')
		size = ft_putchar_printf(va_arg(*arg, int), size);
	else if (type == 's')
		size = ft_putstr_printf(va_arg(*arg, char *), size);
	else if (type == 'p')
	{
		size = ft_putstr_printf("0x", size);
		size = ft_puthexa_printf(va_arg(*arg, uintptr_t),
				"0123456789abcdef", size);
	}
	else if (type == 'd' || type == 'i')
		size = ft_putnbr_printf(va_arg(*arg, int), size);
	else if (type == 'u')
		size = ft_putunbr_printf(va_arg(*arg, unsigned int), size);
	else if (type == 'x')
		size = ft_puthexa_printf(va_arg(*arg, unsigned int),
				"0123456789abcdef", size);
	else if (type == 'X')
		size = ft_puthexa_printf(va_arg(*arg, unsigned int),
				"0123456789ABCDEF", size);
	else if (type == '%')
		size = ft_putchar_printf('%', size);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int				size;
	va_list			arg;

	size = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			size = ft_sort_printf(&arg, *++format, size);
		else
			size = ft_putchar_printf(*format, size);
		format++;
	}
	va_end(arg);
	return (size);
}
