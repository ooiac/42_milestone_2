/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:45:35 by caida-si          #+#    #+#             */
/*   Updated: 2025/07/08 18:48:01 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex_ptr(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		put_hex_ptr(n / 16);
	write(1, &base[n % 16], 1);
}

static int	hex_ptr_len(unsigned long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	print_ptr(va_list args)
{
	unsigned long	ptr;
	int				len;

	ptr = (unsigned long)va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	ft_putstr_fd("0x", 1);
	put_hex_ptr(ptr);
	len = hex_ptr_len(ptr) + 2;
	return (len);
}
