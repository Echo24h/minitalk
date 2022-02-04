/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:17:20 by gborne            #+#    #+#             */
/*   Updated: 2022/01/09 18:19:44 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;

	i = -1;
	j = 0;
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	while (++i <= len)
	{
		while (haystack[i + j] == needle[j] && needle[j] && (len - i - j))
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		j = 0;
	}
	return (NULL);
}
