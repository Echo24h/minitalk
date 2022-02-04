/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:17:20 by gborne            #+#    #+#             */
/*   Updated: 2022/01/09 18:18:04 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (dst[i] && dstsize - i)
		i++;
	if (dstsize - i)
	{
		while (src[j] && (dstsize - i - 1))
			dst[i++] = src[j++];
		dst[i] = 0;
	}
	return (i - j + ft_strlen(src));
}
