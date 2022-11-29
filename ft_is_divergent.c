/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_divergent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:59:30 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/29 17:57:06 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_is_div(t_comp_nb pos, t_comp_nb (*f)(double, double), int r)
{
	int			n;
	int			i;
	t_comp_nb	ite;

	n = 0;
	i = 80;
	ite = pos;
	while (n != i && ite.x <= r && ite.x >= -r && ite.y <= r && ite.y >= -r)
	{
		ite = f(ite.x, ite.y);
		n++;
	}
	n = i - n;
	return (n);
}
