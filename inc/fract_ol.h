/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:30:42 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/05 17:50:42 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H

# define FRACT_OL_H

# include "../libft/includes/libft.h"
# include "key.h"
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
	int		fractal_type;
	int		color;
	double	max_ite;
	double	xcam;
	double	ycam;
	double	zoom;
	double	zoomlimit;
	double	real;
	double	imaginary;
}		t_info;

typedef struct p_list
{
	double	x;
	double	y;
}		t_com_nb;

/*					main					*/
void		ft_draw_fract(t_info info);

/*					ft_graphics				*/
void		ft_create_win(t_info *info);
void		my_mlx_pixel_put(t_info *info, int x, int y, int color);
t_com_nb	ft_convert_axis(int x, int y, t_info info);
t_com_nb	ft_zoom(int x, int y, t_info info);

/*					ft_newton				*/
t_info		ft_newton_info(void);
double		ft_newton(double r, double i, t_info info);

/*					ft_mandelbrot			*/
double		ft_mandelbrot(double r, double i, t_info info);
t_info		ft_mandelbrot_info(void);

/*					ft_julia				*/
double		ft_julia(double r, double i, t_info info);
t_info		ft_julia_info(void);

/*					ft_colors				*/
void		ft_put_color(t_info info, double n, int x, int y);

/*					ft_printinfo			*/
void		ft_print_info(int key, t_info info);
int			ft_check_choice(int argc, char **argv);

/*					ft_hook					*/
int			deal_mouse(int key, int x, int y, t_info *info);
int			deal_key(int key, t_info *info);

#endif
