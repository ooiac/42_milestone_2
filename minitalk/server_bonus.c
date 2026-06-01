/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:39:55 by caida-si          #+#    #+#             */
/*   Updated: 2025/07/31 18:22:09 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bits = 0;
	pid_t					client_pid;

	(void)context;
	client_pid = info->si_pid;
	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;
	bits++;
	if (bits == 8)
	{
		ft_putchar_fd(c, 1);
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		c = 0;
		bits = 0;
	}
	if (kill(client_pid, SIGUSR1) == -1)
		write(2, "Error: failed to send ACK\n", 25);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = &sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
