/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_axis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:04:46 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/29 17:59:24 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_comp_nb	ft_convert_axis(int x, int y)
{
	double			size_x;
	double			size_y;
	int				square_tall;
	t_comp_nb		pos;

	size_x = 1920;
	size_y = 1080;
	square_tall = 1000;
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
	pos.y = (pos.y / square_tall);
	pos.x = (pos.x / square_tall);
	return (pos);
}
