/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 03:05:53 by gborne            #+#    #+#             */
/*   Updated: 2022/01/25 03:05:56 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int numb;

	if (n < 0)
	{
		ft_putchar('-');
		numb = -n;
	}
	else
		numb = n;
	if (numb >= 10)
	{
		ft_putnbr(numb / 10);
		ft_putnbr(numb % 10);
	}
	else
		ft_putchar(numb + 48);
}
