/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:50:52 by caida-si          #+#    #+#             */
/*   Updated: 2025/07/08 18:48:09 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char format, va_list args)
{
	if (format == 'c')
		return (print_char(args));
	else if (format == 's')
		return (print_str(args));
	else if (format == 'd' || format == 'i')
		return (print_int(args));
	else if (format == 'u')
		return (print_uint(args));
	else if (format == 'x')
		return (print_hex(args, 0));
	else if (format == 'X')
		return (print_hex(args, 1));
	else if (format == 'p')
		return (print_ptr(args));
	else if (format == '%')
		return (write(1, "%", 1));
	else
		return (write(1, &format, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += check_format(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
