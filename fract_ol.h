/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:30:42 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/02 19:36:08 by cpapot           ###   ########.fr       */
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
	void	*img_addrs;
	void	*img;
	int		bit_per_p;
	int		line_len;
	int		endian;
	int		xsize;
	int		ysize;
	int		move_ratio;
	double	xcam;
	double	ycam;
	double	zoom;
	double	zoomlimit;
}		t_info;

typedef struct p_list
{
	double	x;
	double	y;
}		t_com_nb;

/*					ft_graphics				*/
void		ft_create_win(t_info *info);
void		my_mlx_pixel_put(t_info *info, int x, int y, int color);
t_com_nb	ft_convert_axis(int x, int y, t_info info);

t_com_nb	ft_mandelbrot(double r, double i);
double		ft_fractal(double r, double i);
void		ft_put_color(t_info info, double n, int x, int y);
void		ft_print_info(int key, t_info info);
t_com_nb	ft_zoom(int x, int y, t_info info);

#endif
