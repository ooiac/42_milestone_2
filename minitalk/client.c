/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:48:40 by caida-si          #+#    #+#             */
/*   Updated: 2025/08/04 19:02:15 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		usleep(400);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		write(2, "Usage: ./client [PID] [MESSAGE]\n", 32);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "Error: Invalid PID\n", 19);
		return (1);
	}
	i = 0;
	while (argv[2][i])
	{
		send_char(argv[2][i], pid);
		i++;
	}
	send_char('\0', pid);
	return (0);
}
