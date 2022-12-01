/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:21:34 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/01 19:07:11 by cpapot           ###   ########.fr       */
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
	ft_printf("%s %d\n", "input:", key);
	if (key == 126)
		cpy.ycam -= cpy.move_ratio;
	else if (key == 125)
		cpy.ycam += cpy.move_ratio;
	else if (key == 123)
		cpy.xcam -= cpy.move_ratio;
	else if (key == 124)
		cpy.xcam += cpy.move_ratio;
	else if (key == 69)
		cpy.zoom *= 1.5;
	else if (key == 78)
		cpy.zoom /= 1.5;
	ft_draw_fract(cpy);
	*info = cpy;
	return (key);
}

int	deal_mousse(int key, t_info *info)
{
	ft_printf("%s %d\n", "input:", key);
	return (info->zoom);
}

t_info	ft_programinfo(void)
{
	t_info	info;

	info.xsize = 1080;
	info.ysize = 720;
	info.zoom = 1;
	info.xcam = 0;
	info.ycam = 0;
	info.move_ratio = 35;
	return (info);
}

int	main(void)
{
	t_info	info;

	info = ft_programinfo();
	ft_create_win(&info);
	ft_draw_fract(info);
	mlx_hook(info.win_ptr, 2, 1L<<0, deal_key, &info);
	mlx_loop(info.mlx_ptr);
}
