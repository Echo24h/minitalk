/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:01:58 by gborne            #+#    #+#             */
/*   Updated: 2022/02/04 07:55:07 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			return (write(1, "ERROR: invalid pid -> main().", 33));
		send_str(argv[2], server_pid);
		return (0);
	}
	return (write(1, "Usage: ./client [server pid] ", 30));
}
