/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:30:42 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/30 18:45:43 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H

# define FRACT_OL_H

# include "lib/libft/includes/libft.h"
# include "lib/libft/srcs/ft_printf/ft_printf.h"
# include "lib/mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_info
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img_ptr;
	int		xsize;
	int		ysize;
	int		xcam;
	int		ycam;
	double	zoom;
	double	born;
	double	c;
}		t_info;

typedef struct p_list
{
	double	x;
	double	y;
}		t_com_nb;

void		*ft_create_win(t_info info);

int			ft_is_div(t_com_nb pos, t_com_nb (*f)(double, double, t_info), t_info info);
t_com_nb	ft_mandelbrot(double r, double i, t_info info);
t_com_nb	ft_convert_axis(int x, int y, t_info info);

#endif
