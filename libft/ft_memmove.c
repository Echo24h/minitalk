/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:17:01 by gborne            #+#    #+#             */
/*   Updated: 2022/01/09 18:17:03 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;

	i = -1;
	if ((dst || src) && dst > src)
		ft_memcpy(dst, src, len);
	if ((dst || src) && dst < src)
		while (++i < len)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}
