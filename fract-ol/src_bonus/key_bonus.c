/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:59:31 by caida-si          #+#    #+#             */
/*   Updated: 2025/09/08 12:59:32 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_handler_bonus(int keysym, t_fractol *fractol)
{
	if (keysym == ESC_KEY)
		close_handler(fractol);
	else if (keysym == ARROW_LEFT)
	{
		fractol->offset_x -= 0.1 / fractol->zoom;
		fractol_render(fractol);
	}
	else if (keysym == ARROW_RIGHT)
	{
		fractol->offset_x += 0.1 / fractol->zoom;
		fractol_render(fractol);
	}
	else if (keysym == ARROW_UP)
	{
		fractol->offset_y -= 0.1 / fractol->zoom;
		fractol_render(fractol);
	}
	else if (keysym == ARROW_DOWN)
	{
		fractol->offset_y += 0.1 / fractol->zoom;
		fractol_render(fractol);
	}
	return (0);
}
