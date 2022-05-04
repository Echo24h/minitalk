/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:01:58 by gborne            #+#    #+#             */
/*   Updated: 2022/04/28 18:39:27 by gborne           ###   ########.fr       */
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
		usleep(1000);
		i++;
	}
}

void	send_str(char *str, int server_pid)
{
	int	i;

	i = -1;
	while (str[++i])
		send_char(str[i], server_pid);
	send_char(0, server_pid);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
			return (write(1, "Error\nInvalid PID", 18));
		send_str(argv[2], server_pid);
		return (0);
	}
	return (write(1, "Usage: ./client [server PID] \"string\"", 30));
}
