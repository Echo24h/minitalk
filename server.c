/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:01:27 by gborne            #+#    #+#             */
/*   Updated: 2022/05/11 17:24:37 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	unsigned int	numb;

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

void	receptor(int sig, siginfo_t *info, void *context)
{
	static char	c = '\0';
	static int	bit_weight = 1;
	static int	signal_len = sizeof(char) * 8;
	static int	clt_pid;

	(void)context;
	if (info->si_pid)
		clt_pid = info->si_pid;
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
	usleep(20);
	kill(clt_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receptor;
	pid = getpid();
	write(1, "Server PID: ", 13);
	ft_putnbr(pid);
	write(1, "\n", 2);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
