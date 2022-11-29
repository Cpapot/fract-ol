/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:45:23 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/29 14:43:42 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	*ft_create_win(void *mlx_ptr)
{
	void	*win_ptr;
	int		size_x;
	int		size_y;

	size_x = 1920;
	size_y = 1080;
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, "Fractol");
	return (win_ptr);
}
