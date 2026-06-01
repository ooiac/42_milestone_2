/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:58:48 by caida-si          #+#    #+#             */
/*   Updated: 2025/09/08 12:59:18 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	close_handler(t_fractol *fractol)
{
	clean_exit(fractol);
	return (0);
}

static void	zoom_at_point(t_fractol *fractol, int x, int y, double zoom_factor)
{
	double	mouse_r;
	double	mouse_i;
	double	center_r;
	double	center_i;
	double	range;

	center_r = -0.5 + fractol->offset_x;
	center_i = 0.0 + fractol->offset_y;
	range = 4.0 / fractol->zoom;
	mouse_r = center_r - range / 2 + ((double)x / WIDTH) * range;
	mouse_i = center_i - range / 2 + ((double)y / HEIGHT) * range;
	fractol->offset_x += (mouse_r - center_r) * (1 - 1 / zoom_factor);
	fractol->offset_y += (mouse_i - center_i) * (1 - 1 / zoom_factor);
	fractol->zoom *= zoom_factor;
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	if (button == MOUSE_WHEEL_UP)
	{
		zoom_at_point(fractol, x, y, 1.1);
		fractol_render(fractol);
	}
	else if (button == MOUSE_WHEEL_DOWN)
	{
		zoom_at_point(fractol, x, y, 0.9);
		fractol_render(fractol);
	}
	return (0);
}
