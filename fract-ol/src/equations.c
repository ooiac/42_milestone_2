/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:59:26 by caida-si          #+#    #+#             */
/*   Updated: 2025/09/08 12:59:08 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c)
{
	int		i;
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4.0)
			return (i);
		zi = 2.0 * zr * zi + c.i;
		zr = zr2 - zi2 + c.r;
		++i;
	}
	return (i);
}

int	julia(t_complex z, t_complex c)
{
	int		i;
	double	zr2;
	double	zi2;
	double	tmp;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		zr2 = z.r * z.r;
		zi2 = z.i * z.i;
		if (zr2 + zi2 > 4.0)
			return (i);
		tmp = zr2 - zi2 + c.r;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = tmp;
		++i;
	}
	return (i);
}
