/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:21:34 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/29 18:03:37 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_draw_fract(void *mlx_ptr, void *win_ptr)
{
	int		n;
	int		x;
	int		y;

	x = 0;
	while (x != 1920)
	{
		y = 0;
		while (y != 1080)
		{
			n = ft_is_div(ft_convert_axis(x, y), ft_mandelbrot, 2);
			if (n == 0)
				mlx_pixel_put (mlx_ptr, win_ptr, x, y, 0xd23033);
			else if (n == 1)
				mlx_pixel_put (mlx_ptr, win_ptr, x, y, 0xd74547);
			else if (n == 2)
				mlx_pixel_put (mlx_ptr, win_ptr, x, y, 0xdb595c);
			else if (n == 3)
				mlx_pixel_put (mlx_ptr, win_ptr, x, y, 0xe06e70);
			else if (n == 4)
				mlx_pixel_put (mlx_ptr, win_ptr, x, y, 0xe48385);
			else if (n == 5)
				mlx_pixel_put (mlx_ptr, win_ptr, x, y, 0xe99899);
			else if (n == 6)
				mlx_pixel_put (mlx_ptr, win_ptr, x, y, 0xedacad);
			else if (n == 7)
				mlx_pixel_put (mlx_ptr, win_ptr, x, y, 0xf2c1c2);
			else
				mlx_pixel_put (mlx_ptr, win_ptr, x, y, 0xffffff);
			y++;
		}
		printf ("%d\n", x);
		x++;

	}
	mlx_loop(mlx_ptr);
}
/*
int	deal_key(int key, void *param)
{
	write (1,"x",1);
	return (0);
}
*/
int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		n;
	int		x;
	int		y;

	x = 0;
	mlx_ptr = mlx_init();
	win_ptr = ft_create_win(mlx_ptr);
	ft_draw_fract(mlx_ptr, win_ptr);
	//mlx_key_hook(win_ptr, deal_key, 1);
	mlx_loop(mlx_ptr);
}


//gcc -g mlx/libmlx.a libft/libft.a ft_printf/libftprintf.a main.c ft_create_win.c ft_convert_axis.c ft_is_divergent.c ft_mandelbrot.c -framework OpenGL -framework AppKit -Lmlx -lmlx -o fractol
