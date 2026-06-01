/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:00:03 by caida-si          #+#    #+#             */
/*   Updated: 2025/07/31 11:07:02 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static unsigned char	c = 0;
	static int				bits = 0;

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
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}
