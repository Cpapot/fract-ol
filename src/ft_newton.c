/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:10:00 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/06 18:27:09 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

t_info	ft_newton_info(void)
{
	t_info	info;

	info.xsize = 700;
	info.ysize = 700;
	info.zoom = 0.7;
	info.xcam = 0;
	info.ycam = 0;
	info.move_ratio = 15;
	info.zoomlimit = 0.5;
	info.fractal_type = 3;
	info.max_ite = 50;
	info.real = 0.418000;
	info.imaginary = -0.010000;
	return (info);
}

double	ft_newton(double r, double i, t_info info)
{
	double		max_iter;
	double		x;
	double		y;
	double		tmp;
	double		u;

	y = i;
	x = r;
	u = 0;
	max_iter = info.max_ite;
	while (u < max_iter)
	{
		tmp = (x * x * x) - 3 * x * (y * y) + info.real;
		y = 3 * (x * x) * y - (y * y * y) + info.imaginary;
		x = tmp;
		if (x * x + y * y > 4)
			return (u / max_iter);
		u++;
	}
	return (1);
}
