/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:02:12 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/06 14:20:48 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	ft_weird(t_info info, double n, int x, int y)
{
	int	i = 0;
	const uint16_t COLOR_TABLE[143] = { // HTML color
  0xf7df, 0xff5a, 0x07ff, 0x7ffa, 0xf7ff, 0xf7bb, 0xff38, 0xff59, 0x001f, 0x895c,
  0xa145, 0xddd0, 0x5cf4, 0x7fe0, 0xd343, 0xfbea, 0x64bd, 0xffdb, 0xd8a7, 0x7ff,
  0x0011, 0x0451, 0xbc21, 0xad55, 0x0320, 0xbdad, 0x8811, 0x5345, 0xfc60, 0x9999,
  0x8800, 0xecaf, 0x8df1, 0x49f1, 0x2a69, 0x067a, 0x901a, 0xf8b2, 0x05ff, 0x6b4d,
  0x1c9f, 0xd48e, 0xb104, 0xffde, 0x2444, 0xf81f, 0xdefb, 0xffdf, 0xfea0, 0xdd24,
  0x8410, 0x0400, 0xafe5, 0xf7fe, 0xfb56, 0xcaeb, 0x4810, 0xfffe, 0xf731, 0xe73f,
  0xff9e, 0x7fe0, 0xffd9, 0xaedc, 0xf410, 0xe7ff, 0xffda, 0xd69a, 0x9772, 0xfdb8,
  0xfd0f, 0x2595, 0x867f, 0x839f, 0x7453, 0xb63b, 0xfffc, 0x07e0, 0x3666, 0xff9c,
  0xf81f, 0x8000, 0x6675, 0x0019, 0xbaba, 0x939b, 0x3d8e, 0x7b5d, 0x07d3, 0x4e99,
  0xc0b0, 0x18ce, 0xf7ff, 0xff3c, 0xff36, 0xfef5, 0x0010, 0xffbc, 0x8400, 0x6c64,
  0xfd20, 0xfa20, 0xdb9a, 0xef55, 0x9fd3, 0xaf7d, 0xdb92, 0xff7a, 0xfed7, 0xcc27,
  0xfe19, 0xdd1b, 0xb71c, 0x8010, 0xf800, 0xbc71, 0x435c, 0x8a22, 0xfc0e, 0xf52c,
  0x2c4a, 0xffbd, 0xa285, 0xc618, 0x867d, 0x6ad9, 0x7412, 0xffdf, 0x07ef, 0x4416,
  0xd5b1, 0x0410, 0xddfb, 0xfb08, 0x471a, 0xec1d, 0xd112, 0xf6f6, 0xffff, 0xf7be,
  0xffe0, 0x9e66, 0x0000};
  n *= 143;
  i = (int)n;
  my_mlx_pixel_put(&info, x, y, COLOR_TABLE[i]);

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
	else if (n <= 0.2)
		my_mlx_pixel_put(&info, x, y, 0xffe400);
	else
		my_mlx_pixel_put(&info, x, y, 0xffffff);
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
		ft_weird(info, n, x, y);
}
