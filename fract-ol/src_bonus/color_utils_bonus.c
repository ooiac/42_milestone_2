/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:58:39 by caida-si          #+#    #+#             */
/*   Updated: 2025/09/08 12:59:16 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	extract_rgb(int color, int *r, int *g, int *b)
{
	*r = (color >> 16) & 0xFF;
	*g = (color >> 8) & 0xFF;
	*b = color & 0xFF;
}

int	interpolate(int start_color, int end_color, double t)
{
	int	start_rgb[3];
	int	end_rgb[3];
	int	result_rgb[3];

	extract_rgb(start_color, &start_rgb[0], &start_rgb[1], &start_rgb[2]);
	extract_rgb(end_color, &end_rgb[0], &end_rgb[1], &end_rgb[2]);
	result_rgb[0] = start_rgb[0] + (int)((end_rgb[0] - start_rgb[0]) * t);
	result_rgb[1] = start_rgb[1] + (int)((end_rgb[1] - start_rgb[1]) * t);
	result_rgb[2] = start_rgb[2] + (int)((end_rgb[2] - start_rgb[2]) * t);
	return ((result_rgb[0] << 16) | (result_rgb[1] << 8) | result_rgb[2]);
}

static void	init_colors(int *colors)
{
	colors[0] = 0xFF6B35;
	colors[1] = 0xF7931E;
	colors[2] = 0xFFD23F;
	colors[3] = 0x06FFA5;
	colors[4] = 0x4ECDC4;
	colors[5] = 0x45B7D1;
}

int	get_color(int i, int max_iterations)
{
	double	t;
	int		colors[6];
	int		segment;

	if (i == max_iterations)
		return (BLACK);
	init_colors(colors);
	t = (double)i / max_iterations;
	t = t * 5;
	segment = (int)t;
	t = t - segment;
	if (segment >= 5)
		return (colors[5]);
	return (interpolate(colors[segment], colors[segment + 1], t));
}
