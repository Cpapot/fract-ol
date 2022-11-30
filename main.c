/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:21:34 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/30 18:53:48 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_draw_fract(t_info info)
{
	int		n;
	int		x;
	int		y;

	x = 0;
	while (x != info.xsize)
	{
		y = 0;
		while (y != info.ysize)
		{
			n = ft_is_div(ft_convert_axis(x, y, info), ft_mandelbrot, info);
			if (n == 0)
				mlx_pixel_put (info.img_ptr, info.win_ptr, x, y, 0xd23033);
			else if (n <= 10)
				mlx_pixel_put (info.img_ptr, info.win_ptr, x, y, 0xd74547);
			else if (n <= 20)
				mlx_pixel_put (info.img_ptr, info.win_ptr, x, y, 0xdb595c);
			else if (n <= 30)
				mlx_pixel_put (info.img_ptr, info.win_ptr, x, y, 0xe06e70);
			else if (n <= 40)
				mlx_pixel_put (info.img_ptr, info.win_ptr, x, y, 0xe48385);
			else if (n <= 50)
				mlx_pixel_put (info.img_ptr, info.win_ptr, x, y, 0xe99899);
			else if (n <= 70)
				mlx_pixel_put (info.img_ptr, info.win_ptr, x, y, 0xedacad);
			else if (n <= 80)
				mlx_pixel_put (info.img_ptr, info.win_ptr, x, y, 0xf2c1c2);
			else
				mlx_pixel_put (info.img_ptr, info.win_ptr, x, y, 0xffffff);
			y++;
		}
		ft_printf("%d\n", x);
		x++;
	}
}

int	deal_key(int key, t_info *info)
{
	t_info	test;

	test = *info;
	write(1,".",1);
	test.zoom += 50;
	ft_draw_fract(test);
	*info = test;
	return (key);
}

t_info	ft_programinfo(void)
{
	t_info	info;

	info.xsize = 1920;
	info.ysize = 1080;
	info.zoom = 10;
	info.born = 2;
	info.xcam = 0;
	info.ycam = 0;
	info.c = -0.75;
	return (info);
}

int	main(void)
{
	t_info	info;
	int		n;
	int		x;
	int		y;

	x = 0;
	info = ft_programinfo();
	info.mlx_ptr = mlx_init();
	info.win_ptr = ft_create_win(info);
	info.img_ptr = mlx_new_image(info.mlx_ptr, info.xsize, info.ysize);
	ft_draw_fract(info);
	mlx_key_hook(info.win_ptr, deal_key, &info);
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img_ptr, 0, 0);
	mlx_loop(info.mlx_ptr);
}
