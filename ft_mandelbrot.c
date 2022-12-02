/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:01:43 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/02 15:47:33 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_com_nb	ft_mandelbrot(double r, double i)
{
	t_com_nb	pos;

	pos.x = (r * r - i * i);
	pos.y = (r * i + r * i);
	return (pos);
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
