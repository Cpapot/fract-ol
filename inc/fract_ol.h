/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:30:42 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/08 16:06:06 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H

# define FRACT_OL_H

# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
#  define KB_ESC		65307
#  define KB_W			122
#  define KB_A			113
#  define KB_S			115
#  define KB_D			100
#  define KB_UP			65362
#  define KB_DOWN		65364
#  define KB_LEFT		65361
#  define KB_RIGHT		65363
#  define KB_N			110
#  define KB_M			44
#  define KB_J			106
#  define KB_K			107
#  define KB_I			105
#  define KB_U			117
#  define KP_4			65430
#  define KP_3			65435
#  define KP_2			65433
#  define KP_1			65436
#  define KB_TAB		65289
#  define KP_PLUS		65451
#  define KP_MINUS		65453
# elif __APPLE__
#  include "../mlx/mlx.h"
#  define KB_ESC		53
#  define KB_W			13
#  define KB_A			0
#  define KB_S			1
#  define KB_D			2
#  define KB_UP			126
#  define KB_DOWN		125
#  define KB_LEFT		123
#  define KB_RIGHT		124
#  define KB_N			45
#  define KB_M			46
#  define KB_J			38
#  define KB_K			40
#  define KB_I			34
#  define KB_U			32
#  define KP_4			86
#  define KP_3			85
#  define KP_2			84
#  define KP_1			83
#  define KB_TAB		48
#  define KP_PLUS		69
#  define KP_MINUS		78
# endif

# include "../libft/includes/libft.h"
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
	double	n;
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
t_com_nb	ft_mousse_pos(int x, int y, t_info info);

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
void		ft_put_color(t_info info, int x, int y);

/*					ft_printinfo			*/
int			ft_check_choice(int argc, char **argv);

/*					ft_hook					*/
int			deal_mouse(int key, int x, int y, t_info *info);
int			deal_key(int key, t_info *info);

/*					ft_preset				*/
void		ft_julia_preset(int key, t_info *info);
void		ft_newton_preset(int key, t_info *info);
void		ft_mandelbrot_preset(int key, t_info *info);

#endif
