/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:29:01 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/05 00:58:46 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

int	deal_key2(int key, t_info *info)
{
	t_info	cpy;

	cpy = *info;
	if (key == 40 && cpy.fractal_type == 2)
		cpy.real += 0.001;
	else if (key == 38 && cpy.fractal_type == 2)
		cpy.real -= 0.001;
	else if (key == 46 && cpy.fractal_type == 2)
		cpy.imaginary += 0.001;
	else if (key == 45 && cpy.fractal_type == 2)
		cpy.imaginary -= 0.001;
	else if (key == KP_1 && cpy.fractal_type == 2)
	{
		cpy.real = 0.355;
		cpy.imaginary = 0.355;
	}
	else if (key == KP_2 && cpy.fractal_type == 2)
	{
		cpy.real = 0;
		cpy.imaginary = 0.8;
	}
	else if (key == KP_4 && cpy.fractal_type == 2)
	{
		cpy.real = -0.54;
		cpy.imaginary = 0.54;
	}
	ft_draw_fract(cpy);
	*info = cpy;
	ft_print_info(key, *info);
	return (key);
}

int	deal_key(int key, t_info *info)
{
	t_info	cpy;

	cpy = *info;
	if (key == KB_UP || key == 13)
		cpy.ycam -= cpy.move_ratio;
	else if (key == KB_DOWN || key == 1)
		cpy.ycam += cpy.move_ratio;
	else if (key == KB_LEFT || key == 0)
		cpy.xcam -= cpy.move_ratio;
	else if (key == KB_RIGHT || key == 2)
		cpy.xcam += cpy.move_ratio;
	else if (key == KB_ESC)
		exit(EXIT_SUCCESS);
	else if (key == 32)
		cpy.max_ite -= 2;
	else if (key == 34)
		cpy.max_ite += 2;
	else
		return (deal_key2(key, info));
	ft_draw_fract(cpy);
	*info = cpy;
	ft_print_info(key, *info);
	return (key);
}

int	deal_mouse(int key, int x, int y, t_info *info)
{
	t_info		cpy;
	t_com_nb	mouse_pos;

	cpy = *info;
	if (key == 4 || key == 2)
	{
		if (cpy.zoom >= cpy.zoomlimit)
			return (key);
		cpy.zoom *= 1.1;
	}
	else if (key == 5 || key == 1)
		cpy.zoom /= 1.1;
	else
		return (key);
	mouse_pos = ft_zoom(x, y, *info);
	cpy.xcam = (mouse_pos.x + cpy.xcam);
	cpy.ycam = (mouse_pos.y + cpy.ycam);
	ft_draw_fract(cpy);
	*info = cpy;
	ft_print_info(key, *info);
	return (key);
}