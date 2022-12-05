/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:01:43 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/05 01:10:58 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

t_info	ft_mandelbrot_info(void)
{
	t_info	info;

	info.xsize = 700;
	info.ysize = 700;
	info.zoom = 1;
	info.xcam = -140;
	info.ycam = 0;
	info.move_ratio = 15;
	info.zoomlimit = 2;
	info.fractal_type = 1;
	info.max_ite = 25;
	return (info);
}

double	ft_mandelbrot(double r, double i, t_info info)
{
	double		max_iter;
	double		x;
	double		y;
	double		tmp;
	double		u;

	y = 0;
	x = 0;
	u = 0;
	max_iter = info.max_ite;
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
