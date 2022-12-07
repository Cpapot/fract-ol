/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:02:12 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/07 22:35:20 by cpapot           ###   ########.fr       */
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

void	ft_put_color(t_info info, double n, int x, int y)
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

	s = info.color % 5;
	info.n = n;
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
}
