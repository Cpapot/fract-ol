/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:45:23 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/01 19:02:37 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_create_win(t_info *info)
{
	t_info	win;

	win = *info;
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, win.xsize, win.ysize, "Fractol");
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
	if ((double)x >= size_x / 2)
		pos.x = -((size_x / 2) - (double)x);
	else
		pos.x = (double)x - (size_x / 2);
	if ((double)y >= size_x / 2)
		pos.y = -((size_y / 2) - (double)y);
	else
		pos.y = (double)y - (size_y / 2);
	pos.y = ((pos.y) / 480) + (info.ycam / 480);
	pos.x = ((pos.x) / 480) + (info.xcam / 480);
	pos.x *= info.zoom;
	pos.y *= info.zoom;
	return (pos);
}
