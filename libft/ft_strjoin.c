/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:17:20 by gborne            #+#    #+#             */
/*   Updated: 2022/02/02 17:09:43 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dst = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	ft_strlcat(dst, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (dst);
}
