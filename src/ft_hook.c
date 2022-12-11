/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:29:01 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/11 23:12:03 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

int	deal_key3(int key, t_info *info)
{
	t_info	cpy;

	cpy = *info;
	if (info->fractal_type == 1)
		ft_mandelbrot_preset(key, info);
	else if (info->fractal_type == 2)
		ft_julia_preset(key, info);
	else if (info->fractal_type == 3)
		ft_newton_preset(key, info);
	ft_draw_fract(cpy);
	*info = cpy;
	return (key);
}

int	deal_key2(int key, t_info *info)
{
	t_info	cpy;

	cpy = *info;
	if (key == KB_K && (cpy.fractal_type == 2 || cpy.fractal_type == 3))
		cpy.real += 0.001;
	else if (key == KB_J && (cpy.fractal_type == 2 || cpy.fractal_type == 3))
		cpy.real -= 0.001;
	else if (key == KB_M && (cpy.fractal_type == 2 || cpy.fractal_type == 3))
		cpy.imaginary += 0.001;
	else if (key == KB_N && (cpy.fractal_type == 2 || cpy.fractal_type == 3))
		cpy.imaginary -= 0.001;
	else if (key == KP_PLUS)
		cpy.zoom *= 1.1;
	else if (key == KP_MINUS)
		cpy.zoom /= 1.1;
	else if (key == KB_TAB)
		cpy.color += 1;
	else
		return (deal_key3(key, info));
	if (cpy.zoom <= 0.5)
		cpy.zoom = 0.5;
	ft_draw_fract(cpy);
	*info = cpy;
	return (key);
}

int	deal_key(int key, t_info *info)
{
	t_info	cpy;

	cpy = *info;
	if (key == KB_UP || key == KB_W)
		cpy.ycam -= cpy.move_ratio / cpy.zoom;
	else if (key == KB_DOWN || key == KB_S)
		cpy.ycam += cpy.move_ratio / cpy.zoom;
	else if (key == KB_LEFT || key == KB_A)
		cpy.xcam -= cpy.move_ratio / cpy.zoom;
	else if (key == KB_RIGHT || key == KB_D)
		cpy.xcam += cpy.move_ratio / cpy.zoom;
	else if (key == KB_ESC || key == 17)
		exit(EXIT_SUCCESS);
	else if (key == KB_U)
	{
		if (cpy.max_ite >= 5)
			cpy.max_ite -= 5;
	}
	else if (key == KB_I)
		cpy.max_ite += 5;
	else
		return (deal_key2(key, info));
	ft_draw_fract(cpy);
	*info = cpy;
	return (key);
}

int	deal_mouse(int key, int x, int y, t_info *info)
{
	t_info		cpy;
	t_com_nb	mouse_pos;

	cpy = *info;
	if (key == 4 || key == 2)
	{
		if (cpy.zoom <= cpy.zoomlimit)
			return (key);
		cpy.zoom /= 1.1;
	}
	else if (key == 5 || key == 1)
		cpy.zoom *= 1.1;
	else
		return (key);
	mouse_pos = ft_mousse_pos(x, y, *info);
	cpy.xcam = mouse_pos.x * 225;
	cpy.ycam = mouse_pos.y * 225;
	*info = cpy;
	ft_draw_fract(*info);
	return (key);
}

int	close_window(void)
{
	exit(EXIT_SUCCESS);
}
