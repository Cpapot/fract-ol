/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:45:23 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/08 02:03:02 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	ft_create_win(t_info *info)
{
	char	*man;
	char	*jul;
	char	*new;
	t_info	win;

	man = "Mandelbrot";
	jul = "Julia";
	new = "Newton";
	win = *info;
	win.mlx_ptr = mlx_init();
	if (win.fractal_type == 1)
		win.win_ptr = mlx_new_window(win.mlx_ptr, win.xsize, win.ysize, man);
	else if (win.fractal_type == 2)
		win.win_ptr = mlx_new_window(win.mlx_ptr, win.xsize, win.ysize, jul);
	else if (win.fractal_type == 3)
		win.win_ptr = mlx_new_window(win.mlx_ptr, win.xsize, win.ysize, new);
	win.img = mlx_new_image(win.mlx_ptr, win.xsize, win.ysize);
	win.img_addrs = mlx_get_data_addr(win.img, &win.bit_per_p,
			&win.line_len, &win.endian);
	*info = win;
}

void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->img_addrs + (y * info->line_len + x * (info->bit_per_p / 8));
	*(unsigned int *)dst = color;
}

t_com_nb	ft_convert_axis(int x, int y, t_info info)
{
	int			size_x;
	int			size_y;
	t_com_nb	pos;

	size_x = info.xsize;
	size_y = info.ysize;
	pos.y = (y - size_y / 2.0) / (0.5 * info.zoom * size_y) + info.ycam / 225;
	pos.x = (x - size_x / 2.0) / (0.5 * info.zoom * size_x) + info.xcam / 225;
	return (pos);
}

t_com_nb	ft_mousse_pos(int x, int y, t_info info)
{
	int			size_x;
	int			size_y;
	t_com_nb	pos;

	size_x = info.xsize;
	size_y = info.ysize;
	pos.y = (y - size_y / 2.0) / (0.5 * info.zoom * size_y) + info.ycam / 225;
	pos.x = (x - size_x / 2.0) / (0.5 * info.zoom * size_x) + info.xcam / 225;
	return (pos);
}
