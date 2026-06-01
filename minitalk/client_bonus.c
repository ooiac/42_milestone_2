/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:08:54 by caida-si          #+#    #+#             */
/*   Updated: 2025/07/31 13:50:29 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_bit(int bit, int pid)
{
	int	signal;

	if (bit == 1)
		signal = SIGUSR2;
	else
		signal = SIGUSR1;
	if (kill(pid, signal) == -1)
	{
		write(2, "Error: failed to send the signal\n", 33);
		return ;
	}
	while (!g_ack_received)
		usleep(10);
	g_ack_received = 0;
}

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit((c >> i) & 1, pid);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
	{
		write(2, "Error: Invalid PID or server unavaible\n", 39);
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	i = 0;
	while (argv[2][i])
	{
		send_char(argv[2][i], pid);
		i++;
	}
	send_char('\0', pid);
	write(1, "Message sent succesfully\n", 25);
	return (0);
}
