/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:21:34 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/02 19:38:45 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_draw_fract(t_info info)
{
	double		n;
	t_com_nb	pos;
	int			x;
	int			y;

	x = 0;
	while (x != info.xsize)
	{
		y = 0;
		while (y != info.ysize)
		{
			pos = ft_convert_axis(x, y, info);
			n = ft_fractal(pos.x, pos.y);
			ft_put_color(info, n, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img, 0, 0);
}

int	deal_key(int key, t_info *info)
{
	t_info	cpy;

	cpy = *info;
	if (key == 126)
		cpy.ycam -= cpy.move_ratio;
	else if (key == 125)
		cpy.ycam += cpy.move_ratio;
	else if (key == 123)
		cpy.xcam -= cpy.move_ratio;
	else if (key == 124)
		cpy.xcam += cpy.move_ratio;
	else if (key == 53)
		exit(EXIT_SUCCESS);
	else
		return (key);
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
	cpy.xcam = mouse_pos.x;
	cpy.ycam = mouse_pos.y;
	ft_draw_fract(cpy);
	*info = cpy;
	ft_print_info(key, *info);
	return (key);
}

t_info	ft_programinfo(void)
{
	t_info	info;

	info.xsize = 700;
	info.ysize = 700;
	info.zoom = 1;
	info.xcam = -140;
	info.ycam = 0;
	info.move_ratio = 15;
	info.zoomlimit = 2;
	return (info);
}

int	main(void)
{
	t_info	info;

	info = ft_programinfo();
	ft_create_win(&info);
	ft_draw_fract(info);
	mlx_hook(info.win_ptr, 2, 1L << 0, deal_key, &info);
	mlx_mouse_hook(info.win_ptr, deal_mouse, &info);
	mlx_loop(info.mlx_ptr);
}
