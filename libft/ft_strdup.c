/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:17:20 by gborne            #+#    #+#             */
/*   Updated: 2022/01/09 18:17:54 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*s2;

	s2 = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
