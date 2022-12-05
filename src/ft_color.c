/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:02:12 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/05 01:07:59 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	ft_put_color(t_info info, double n, int x, int y)
{
	if (n == 1)
		my_mlx_pixel_put(&info, x, y, 0x000000);
	else
		my_mlx_pixel_put(&info, x, y, n * 10000);
	/*else if (n >= 0.9)
		my_mlx_pixel_put(&info, x, y, 0x3f2ea2);
	else if (n >= 0.8)
		my_mlx_pixel_put(&info, x, y, 0x2e77a2);
	else if (n >= 0.85)
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
	else if (n >= 0.45)
		my_mlx_pixel_put(&info, x, y, 0x621708);
	else if (n >= 0.4)
		my_mlx_pixel_put(&info, x, y, 0x941b0c);
	else if (n >= 0.35)
		my_mlx_pixel_put(&info, x, y, 0xbc3908);
	else if (n >= 0.3)
		my_mlx_pixel_put(&info, x, y, 0xf6aa1c);
	else if (n >= 0.25)
		my_mlx_pixel_put(&info, x, y, 0xfee440);
	else if (n >= 0.2)
		my_mlx_pixel_put(&info, x, y, 0xdaff7d);
	else if (n >= 0.15)
		my_mlx_pixel_put(&info, x, y, 0x20ac6f);
	else if (n <= 0.2)
		my_mlx_pixel_put(&info, x, y, 0xffe400);
	else
		my_mlx_pixel_put(&info, x, y, 0xffffff);*/
}
