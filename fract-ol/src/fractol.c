/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:59:57 by caida-si          #+#    #+#             */
/*   Updated: 2025/09/08 12:59:10 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	putstr_fd("Usage: ./fractol <fractal_type> [julia_r] [julia_i]\n", 1);
	putstr_fd("Available fractals:\n", 1);
	putstr_fd("  mandelbrot\n", 1);
	putstr_fd("  julia <real> <imaginary>\n", 1);
	putstr_fd("Example: ./fractol julia -0.4 0.6\n", 1);
}

static void	set_fractal_type(t_fractol *fractol, char **av)
{
	if (strncmp(av[1], "mandelbrot", 10) == 0)
		fractol->fractal_type = MANDELBROT;
	else if (strncmp(av[1], "julia", 5) == 0)
	{
		fractol->fractal_type = JULIA;
		fractol->kr = atodbl(av[2]);
		fractol->ki = atodbl(av[3]);
	}
	else
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
}

static void	validate_args(int ac, char **av, t_fractol *fractol)
{
	if (ac < 2)
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
	if (strncmp(av[1], "julia", 5) == 0 && ac != 4)
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
	set_fractal_type(fractol, av);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	validate_args(ac, av, &fractol);
	fractol_init(&fractol);
	fractol_render(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
