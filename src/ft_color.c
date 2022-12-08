/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:02:12 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/08 00:49:26 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	ft_putpalette(const int32_t	*table, t_info info, int x, int y)
{
	double			u;

	u = info.n * info.max_ite;
	if (info.n == 0)
		my_mlx_pixel_put(&info, x, y, 0x00000);
	my_mlx_pixel_put(&info, x, y, table[(int)u % 5]);
}

void	ft_shaded_blue(t_info info, int x, int y)
{
	if (info.n == 1)
		my_mlx_pixel_put(&info, x, y, 0x000000);
	else
		my_mlx_pixel_put(&info, x, y, info.n * 10000);
}

void	ft_more_colors(t_info info, int x, int y, int s)
{
	const int32_t	lava[] = {
		0xa62639, 0xdb324d, 0x56494e, 0xa29c9b, 0x511c29};
	const int32_t	ocean[] = {
		0x03045e, 0x0077b6, 0x00b4d8, 0x90e0ef, 0xcaf0f8};
	const int32_t	grey[] = {
		0x08090a, 0xa7a2a9, 0xf4f7f5, 0x575a5e, 0x222823};
	const int32_t	red_and_blue[] = {
		0x2c1320, 0x5f4b66, 0x5f4b66, 0x8797af, 0x56667a};
	const int32_t	all[] = {
		0xf8ffe5, 0x06d6a0, 0x1b9aaa, 0xef476f, 0xffc43d};

	if (s == 5)
		ft_putpalette(lava, info, x, y);
	else if (s == 6)
		ft_putpalette(ocean, info, x, y);
	else if (s == 7)
		ft_putpalette(grey, info, x, y);
	else if (s == 8)
		ft_putpalette(red_and_blue, info, x, y);
	else if (s == 9)
		ft_putpalette(all, info, x, y);
}

void	ft_put_color(t_info info, int x, int y)
{
	int				s;
	const int32_t	psy[] = {0xfd00ff, 0xfdff00,
		0x00ff38, 0x00f9ff, 0x3c00ff};
	const int32_t	fire[] = {
		0xf7b267, 0xf79d65, 0xf4845f, 0xf27059, 0xf25c54};
	const int32_t	green[] = {
		0xbeef9e, 0xa6c36f, 0x828c51, 0x335145, 0x1e352f};
	const int32_t	pastel[] = {
		0xff99c8, 0xfcf6bd, 0xd0f4de, 0xa9def9, 0xe4c1f9};

	s = info.color % 10;
	if (s == 0)
		ft_shaded_blue(info, x, y);
	else if (s == 1)
		ft_putpalette(psy, info, x, y);
	else if (s == 2)
		ft_putpalette(fire, info, x, y);
	else if (s == 3)
		ft_putpalette(green, info, x, y);
	else if (s == 4)
		ft_putpalette(pastel, info, x, y);
	else
		ft_more_colors(info, x, y, s);
}
