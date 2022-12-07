/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:55:34 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/07 02:41:03 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	ft_julia_preset(int key, t_info *info)
{
	t_info	cpy;

	cpy = *info;
	if (key == KP_1)
	{
		cpy.real = 0.355;
		cpy.imaginary = 0.355;
	}
	else if (key == KP_2)
	{
		cpy.real = 0;
		cpy.imaginary = 0.8;
	}
	else if (key == KP_3)
	{
		cpy.real = -0.54;
		cpy.imaginary = 0.54;
	}
	else if (key == KP_4)
	{
		cpy.real = -0.8;
		cpy.imaginary = 0.156;
	}
	*info = cpy;
}

void	ft_mandelbrot_preset(int key, t_info *info)
{
	t_info	cpy;

	cpy = *info;
	if (key == KP_1)
	{
		cpy.xcam = -329.531892;
		cpy.ycam = 0;
		cpy.zoom = 583702247570;
		cpy.max_ite = 130;
	}
	*info = cpy;
}

void	ft_newton_preset(int key, t_info *info)
{
	t_info	cpy;

	cpy = *info;
	if (key == KP_1)
	{
		cpy.real = -0.59;
		cpy.imaginary = 0.156;
	}
	else if (key == KP_2)
	{
		cpy.real = 0;
		cpy.imaginary = 0.8;
	}
	else if (key == KP_3)
	{
		cpy.real = -0.54;
		cpy.imaginary = 0.54;
	}
	else if (key == KP_4)
	{
		cpy.real = -0.595;
		cpy.imaginary = 0.588;
	}
	*info = cpy;
}
