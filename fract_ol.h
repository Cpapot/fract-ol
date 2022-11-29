/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:30:42 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/29 17:17:58 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H

# define FRACT_OL_H

# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct p_list
{
	double	x;
	double	y;
	double	c;
}		t_comp_nb;

void		*ft_create_win(void *mlx_ptr);

int			ft_is_div(t_comp_nb pos, t_comp_nb (*f)(double, double), int r);
t_comp_nb	ft_mandelbrot(double r, double i);
t_comp_nb	ft_convert_axis(int x, int y);

#endif
