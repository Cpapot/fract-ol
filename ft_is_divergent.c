/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_divergent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:59:30 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/01 14:27:55 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	ft_is_div(t_com_nb pos, double (*f)(double, double))
{
	double		n;
	t_com_nb	ite;

	ite = pos;
	n = f(ite.x, ite.y);
	return (n);
}
