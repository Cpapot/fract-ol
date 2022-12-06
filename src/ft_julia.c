/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:48:30 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/06 18:27:14 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

t_info	ft_julia_info(void)
{
	t_info	info;

	info.xsize = 700;
	info.ysize = 700;
	info.zoom = 0.7;
	info.xcam = 0;
	info.ycam = 0;
	info.move_ratio = 15;
	info.zoomlimit = 0.5;
	info.fractal_type = 2;
	info.max_ite = 50;
	info.real = 0.285;
	info.imaginary = 0.01;
	return (info);
}

double	ft_julia(double r, double i, t_info info)
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
		tmp = x * x - y * y + info.real;
		y = 2 * x * y + info.imaginary;
		x = tmp;
		if (x * x + y * y > 4)
			return (u / max_iter);
		u++;
	}
	return (1);
}
