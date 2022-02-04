/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 03:03:11 by gborne            #+#    #+#             */
/*   Updated: 2022/01/25 03:03:24 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	if (!str1 && !str2)
		return (0);
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
