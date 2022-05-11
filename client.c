/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:01:58 by gborne            #+#    #+#             */
/*   Updated: 2022/05/11 17:23:53 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45 || ft_isdigit(*str))
	{
		if (*str == 45)
			sign = -1;
		if (ft_isdigit(*str))
			result = result * 10 + (*str - 48);
		while (ft_isdigit(*++str))
			result = result * 10 + (*str - 48);
	}
	return (result * sign);
}

void	send_char(char chr, int server_pid)
{
	int	i;

	i = 0;
	if (chr < 0)
		return ;
	while (i < 8)
	{
		if (chr % 2 == 1)
			kill(server_pid, SIGUSR1);
		else if (chr % 2 == 0)
			kill(server_pid, SIGUSR2);
		chr /= 2;
		pause();
		i++;
	}
}

void	empty(int sig)
{
	(void)sig;
}

int	main(int argc, char **argv)
{
	int					server_pid;
	struct sigaction	sa;
	int					i;

	sa.sa_handler = empty;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	i = -1;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
			return (write(1, "Error\nInvalid PID", 18));
		while (argv[2][++i])
			send_char(argv[2][i], server_pid);
		send_char(0, server_pid);
		return (0);
	}
	return (write(1, "Usage: ./client [server PID] \"string\"", 38));
}
