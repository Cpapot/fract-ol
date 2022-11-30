/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:45:23 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/30 17:46:00 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	*ft_create_win(t_info info)
{
	void	*win_ptr;

	win_ptr = mlx_new_window(info.mlx_ptr, info.xsize, info.ysize, "Fractol");
	return (win_ptr);
}
