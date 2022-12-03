/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:01:43 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/03 19:16:32 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	ft_mandelbrot(double r, double i)
{
	double		max_iter;
	double		x;
	double		y;
	double		tmp;
	double		u;

	y = i;
	x = r;
	u = 0;
	max_iter = 55;
	while (u < max_iter)
	{
		tmp = x * x - y * y + 0.285;
		y = 2 * x * y + 0.01;
		x = tmp;
		if (x * x + y * y > 4)
			return (u / max_iter);
		u++;
	}
	return (1);
}

double	ft_fractal(double r, double i)
{
	double		max_iter;
	double		x;
	double		y;
	double		tmp;
	double		u;

	y = 0;
	x = 0;
	u = 0;
	max_iter = 30;
	while (u < max_iter)
	{
		tmp = x * x - y * y + r;
		y = 2 * x * y + i;
		x = tmp;
		if (x * x + y * y > 4)
			return (u / max_iter);
		u++;
	}
	return (1);
}
