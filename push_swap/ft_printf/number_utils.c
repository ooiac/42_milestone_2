/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:40:41 by caida-si          #+#    #+#             */
/*   Updated: 2025/07/08 18:47:59 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list args)
{
	int		n;
	char	*str;
	int		len;

	n = va_arg(args, int);
	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	print_uint(va_list args)
{
	unsigned int	n;
	char			*str;
	int				len;

	n = va_arg(args, unsigned int);
	str = ft_uitoa(n);
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

static void	put_hex(unsigned int n, int is_upper)
{
	char	*base;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16, is_upper);
	write(1, &base[n % 16], 1);
}

static int	hex_len(unsigned int n)
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

int	print_hex(va_list args, int is_upper)
{
	unsigned int	n;
	int				len;

	n = va_arg(args, unsigned int);
	put_hex(n, is_upper);
	len = hex_len(n);
	return (len);
}
