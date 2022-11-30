/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_axis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:04:46 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/30 17:55:15 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_com_nb	ft_convert_axis(int x, int y, t_info info)
{
	double			size_x;
	double			size_y;
	t_com_nb		pos;

	size_x = info.xsize;
	size_y = info.ysize;
	if ((double)x >= size_x / 2)
		pos.x = -((size_x / 2) - (double)x);
	else
		pos.x = (double)x - (size_x / 2);
	if ((double)y >= size_x / 2)
		pos.y = -((size_y / 2) - (double)x);
	else
		pos.y = (double)y - (size_y / 2);
	pos.y = -pos.y;
	pos.y -= 30;
	pos.y = (pos.y / info.zoom);
	pos.x = (pos.x / info.zoom);
	return (pos);
}
