/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:41:24 by caida-si          #+#    #+#             */
/*   Updated: 2025/07/10 13:04:55 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		print_char(va_list args);
int		print_str(va_list args);
int		print_int(va_list args);
int		print_uint(va_list args);
int		print_hex(va_list args, int is_upper);
int		print_ptr(va_list args);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_uitoa(unsigned int n);

#endif
