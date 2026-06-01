/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:00:47 by caida-si          #+#    #+#             */
/*   Updated: 2025/09/05 13:00:49 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

static int	calculate_fractal(t_fractol *fractol, t_complex c)
{
	t_complex	julia_c;

	if (fractol->fractal_type == MANDELBROT)
		return (mandelbrot(c));
	else if (fractol->fractal_type == JULIA)
	{
		julia_c.r = fractol->kr;
		julia_c.i = fractol->ki;
		return (julia(c, julia_c));
	}
	else if (fractol->fractal_type == BURNING_SHIP)
		return (burning_ship(c));
	else if (fractol->fractal_type == TRICORN)
		return (tricorn(c));
	return (0);
}

static void	set_complex_bounds(t_fractol *fractol)
{
	double	center_r;
	double	center_i;
	double	range;

	center_r = -0.5 + fractol->offset_x;
	center_i = 0.0 + fractol->offset_y;
	range = 4.0 / fractol->zoom;
	fractol->min_r = center_r - range / 2;
	fractol->max_r = center_r + range / 2;
	fractol->min_i = center_i - range / 2;
	fractol->max_i = center_i + range / 2;
}

static void	render_pixel(t_fractol *fractol, int x, int y, double *scale)
{
	t_complex	c;
	int			iterations;
	int			color;

	c.r = fractol->min_r + x * scale[0];
	c.i = fractol->min_i + y * scale[1];
	iterations = calculate_fractal(fractol, c);
	color = get_color(iterations, fractol->max_iterations);
	my_pixel_put(&fractol->img, x, y, color);
}

void	fractol_render(t_fractol *fractol)
{
	int		x;
	int		y;
	double	scale[2];

	set_complex_bounds(fractol);
	scale[0] = (fractol->max_r - fractol->min_r) / WIDTH;
	scale[1] = (fractol->max_i - fractol->min_i) / HEIGHT;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			render_pixel(fractol, x, y, scale);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.img, 0, 0);
}
