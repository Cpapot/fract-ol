/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:21:34 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/08 01:02:04 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	ft_draw_fract(t_info info)
{
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
			if (info.fractal_type == 1)
				info.n = ft_mandelbrot(pos.x, pos.y, info);
			else if (info.fractal_type == 2)
				info.n = ft_julia(pos.x, pos.y, info);
			else if (info.fractal_type == 3)
				info.n = ft_newton(pos.x, pos.y, info);
			ft_put_color(info, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img, 0, 0);
	ft_printf("\nRENDER DONE (%d iter)", (int)info.max_ite);
}

int	main(int argc, char **argv)
{
	t_info	info;

	info.fractal_type = ft_check_choice(argc, argv);
	if (info.fractal_type == 0)
		return (0);
	if (info.fractal_type == 1)
		info = ft_mandelbrot_info();
	else if (info.fractal_type == 2)
		info = ft_julia_info();
	else if (info.fractal_type == 3)
		info = ft_newton_info();
	info.color = 0;
	ft_create_win(&info);
	ft_draw_fract(info);
	mlx_hook(info.win_ptr, 2, 1L << 0, deal_key, &info);
	mlx_mouse_hook(info.win_ptr, deal_mouse, &info);
	mlx_loop(info.mlx_ptr);
}
