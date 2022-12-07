/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:02:12 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/07 16:02:35 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	ft_pshychedelic(t_info info, double n, int x, int y)
{
	if (n == 1)
		my_mlx_pixel_put(&info, x, y, 0x000000);
	else if (n >= 0.90)
		my_mlx_pixel_put(&info, x, y, 0xfd00ff);
	else if (n >= 0.8)
		my_mlx_pixel_put(&info, x, y, 0xfdff00);
	else if (n >= 0.7)
		my_mlx_pixel_put(&info, x, y, 0x00ff38);
	else if (n >= 0.6)
		my_mlx_pixel_put(&info, x, y, 0x00f9ff);
	else
		my_mlx_pixel_put(&info, x, y, 0x3c00ff);
}

void	ft_multicolor(t_info info, double n, int x, int y)
{
	if (n == 1)
		my_mlx_pixel_put(&info, x, y, 0x000000);
	else if (n >= 0.95)
		my_mlx_pixel_put(&info, x, y, 0x0be8cd);
	else if (n >= 0.9)
		my_mlx_pixel_put(&info, x, y, 0x3f2ea2);
	else if (n >= 0.85)
		my_mlx_pixel_put(&info, x, y, 0x2e77a2);
	else if (n >= 0.8)
		my_mlx_pixel_put(&info, x, y, 0x2ea1a2);
	else if (n >= 0.75)
		my_mlx_pixel_put(&info, x, y, 0x2ea26b);
	else if (n >= 0.70)
		my_mlx_pixel_put(&info, x, y, 0x2ea23b);
	else if (n >= 0.65)
		my_mlx_pixel_put(&info, x, y, 0x80a22e);
	else if (n >= 0.6)
		my_mlx_pixel_put(&info, x, y, 0xa2922e);
	else if (n >= 0.55)
		my_mlx_pixel_put(&info, x, y, 0xc97f22);
	else if (n >= 0.5)
		my_mlx_pixel_put(&info, x, y, 0xc94722);
	else
		my_mlx_pixel_put(&info, x, y, 0x9e25be);
}

void	ft_shaded_blue(t_info info, double n, int x, int y)
{
	if (n == 1)
		my_mlx_pixel_put(&info, x, y, 0x000000);
	else
		my_mlx_pixel_put(&info, x, y, n * 10000);
}

void	ft_put_color(t_info info, double n, int x, int y)
{
	int	s;

	s = info.color % 3;
	if (s == 0)
		ft_shaded_blue(info, n, x, y);
	else if (s == 1)
		ft_multicolor(info, n, x, y);
	else if (s == 2)
		ft_pshychedelic(info, n, x, y);
}
