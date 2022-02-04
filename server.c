/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:01:27 by gborne            #+#    #+#             */
/*   Updated: 2022/02/04 08:00:36 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receptor(int sig)
{
	static char	c = '\0';
	static int	bit_weight = 1;
	static int	signal_len = sizeof(char) * 8;

	if (sig == SIGUSR1)
		c += bit_weight;
	signal_len--;
	bit_weight *= 2;
	if (signal_len == 0)
	{
		write(1, &c, 1);
		bit_weight = 1;
		signal_len = sizeof(char) * 8;
		c = '\0';
	}
}

int	main()
{
	int pid;

	pid = getpid();
	ft_printf("Entrez ce pid dans le client: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, receptor);
		signal(SIGUSR2, receptor);
		pause();
	}
	return (0);
}
