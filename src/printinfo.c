/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printinfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:46:17 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/11 23:40:19 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	ft_print_fract(void)
{
	ft_printf("\n%s\n", "		     FRACTOL			");
	ft_printf("\n%s\n", "		INCORECT ARGUMENT!		");
	ft_printf("\n%s\n", "   you have to choose one of these fractals:");
	ft_printf("\n%s\n", "		- Mandelb");
	ft_printf("\n%s\n", "		- Julia");
	ft_printf("\n%s\n", "		- Newton");
	ft_printf("\n%s\n", "   (to choose a fractal you must put it in a parameter");
	ft_printf("%s\n\n", "   such as : \"./fractol Mandelb\".)");
}

void	ft_print_control(void)
{
	ft_printf("\n%s\n", "			CONTROLS		");
	ft_printf("\n%s\n", "   Arrow or WASD:			Move camera");
	ft_printf("%s\n", "   Scroll up, Left click or +:		Zoom");
	ft_printf("%s\n", "   Scroll down, right click or -:	Dezoom");
	ft_printf("%s\n", "   Number Tab:				Load Preset");
	ft_printf("%s\n", "   I and U:				Change iterations");
	ft_printf("%s\n", "   K and J:				Change real Nb");
	ft_printf("%s\n", "   N and M:				Change imaginary Nb");
	ft_printf("%s\n", "   TAB:					Change Colors");
}

t_info	ft_check_second_arg_julia(char **argv)
{
	t_info	info;

	info = ft_julia_info();
	if (!ft_strncmp("1", argv[2], 2))
		ft_julia_preset(KP_1, &info);
	else if (!ft_strncmp("2", argv[2], 2))
		ft_julia_preset(KP_2, &info);
	else if (!ft_strncmp("3", argv[2], 2))
		ft_julia_preset(KP_3, &info);
	else if (!ft_strncmp("4", argv[2], 2))
		ft_julia_preset(KP_4, &info);
	return (info);
}

void	ft_check_choice(int argc, char **argv, t_info *info)
{
	info->fractal_type = 0;
	if (argc < 2)
	{
		ft_print_fract();
		return ;
	}
	if (!ft_strncmp("Mandelb", argv[1], 8))
	{
		ft_print_control();
		*info = ft_mandelbrot_info();
	}
	else if (!ft_strncmp("Julia", argv[1], 6) && argc == 2)
	{
		ft_print_control();
		*info = ft_julia_info();
	}
	else if (!ft_strncmp("Newton", argv[1], 7))
	{
		ft_print_control();
		*info = ft_newton_info();
	}
	else if (argc >= 3 && !ft_strncmp("Julia", argv[1], 6))
		*info = ft_check_second_arg_julia(argv);
	ft_print_fract();
}
