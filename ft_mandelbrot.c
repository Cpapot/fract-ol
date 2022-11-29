/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:01:43 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/29 17:57:11 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_comp_nb	ft_mandelbrot(double r, double i)
{
	t_comp_nb	pos;

	pos.c = -0.75;
	pos.x = (r * r - i * i) + pos.c;
	pos.y = (r * i + r * i);
	return (pos);
}
