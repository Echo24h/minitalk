/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:16:11 by gborne            #+#    #+#             */
/*   Updated: 2022/01/10 17:04:50 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
		n++;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*a;
	unsigned int	un;
	size_t			len;

	len = n_len(n);
	if (n < 0)
		un = (unsigned)(n * -1);
	else
		un = (unsigned)n;
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (a != NULL)
	{
		a[len--] = '\0';
		if (n < 0)
			a[0] = '-';
		else if (n == 0)
			a[0] = '0';
		while (un > 0)
		{
			a[len--] = (char)(un % 10 + '0');
			un /= 10;
		}
	}
	return (a);
}
