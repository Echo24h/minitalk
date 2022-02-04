/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:17:20 by gborne            #+#    #+#             */
/*   Updated: 2022/01/09 18:19:51 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned long	start;
	unsigned long	end;
	char			*s2;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	if (start == ft_strlen(s1))
		end = 0;
	while (ft_strchr(set, s1[end]) && end)
		end--;
	if (end)
		end = ft_strlen(s1) - end - 1;
	s2 = (char *)ft_calloc(ft_strlen(s1) - start - end + 1, sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, &s1[start], ft_strlen(s1) - start - end + 1);
	return ((char *)s2);
}
